/*
* Route messages / queues between mutiple program entities.
* Constellations / Stars / Tracks are forwareded between db and tracking logic.
* The router also has access to the MQTT Client to receive messages from outside.
*/

#include "etl/queue.h"
#include "etl/message_router.h"

#include <iostream>
#include <string>

#include "datadelegate.hpp"

//*****************************************************************************
// The messages.
//*****************************************************************************
/*
* Search for constellation by id.
* The returned constellation will be returned as struct constellation.
*/
struct ConstellationRequestMsg : public etl::message<1>
{
  ConstellationRequestMsg(int i_)
    : i(i_)
  {
  }

  int i;
};

struct Message2 : public etl::message<2>
{
  Message2(double d_)
    : d(d_)
  {
  }

  double d;
};
/*
* Add a new constellation to the database.
*
*/
struct ConstellationCreateMsg : public etl::message<3>
{
  ConstellationCreateMsg(const std::string& s_)
    : s(s_)
  {
  }

  std::string s;
};

struct Message4 : public etl::message<4>
{
};

//*****************************************************************************
// The message router.
// Handles message types ConstellationRequestMsg, Message2, ConstellationCreateMsg.
//*****************************************************************************
class Router : public etl::message_router<Router, ConstellationRequestMsg, Message2, ConstellationCreateMsg>
{
public:

  typedef etl::message_router<Router, ConstellationRequestMsg, Message2, ConstellationCreateMsg> Base_t;

  using Base_t::receive;

  //***************************************************************************
  Router()
    : message_router(1)
  {
  }

  //***************************************************************************
  // Override the base class's receive function.
  void receive(const etl::imessage& msg_)
  {
    if (accepts(msg_))
    {
      // Place in queue.
      queue.emplace(msg_);

      std::cout << "Routing message. Its type is: " << int(msg_.get_message_id()) << std::endl;
    }
    else
    {
      std::cout << "Ignoring message, no route available. Its id is: " << int(msg_.get_message_id()) << std::endl;
    }
  }

  //***************************************************************************
  void process_queue()
  {
    while (!queue.empty())
    {
      message_packet& packet = queue.front();
      etl::imessage& msg = packet.get();
      std::cout << "Forwarding message to its handler. Its id is " << int(msg.get_message_id()) << std::endl;

      // Call the base class's receive function.
      // This will route it to the correct on_receive handler.
      Base_t::receive(msg);

      queue.pop();
    }
  }

  //***************************************************************************
  /*
  *  Process a request msg. Returns a constellation struct.
  */
  void on_receive(const ConstellationRequestMsg& msg)
  {
    std::cout << "  Received a constellation request msg. ID,msg.data= " << int(msg.get_message_id()) << " : '" << msg.i << "'" << std::endl;
    //get_constellation();
    // Add constellation to constellation queue:
  }

  //***************************************************************************
  void on_receive(const Message2& msg)
  {
    std::cout << "  Received unimplemented message " << int(msg.get_message_id()) << " : '" << msg.d << "'" << std::endl;
  }

  //***************************************************************************
  /*
  * Add new constellation to the database
  */
  void on_receive(const ConstellationCreateMsg& msg)
  {
    std::cout << "  Received a Constellation Create message ID,msg.data= " << int(msg.get_message_id()) << " : '" << msg.s << "'" << std::endl;
    //add_constellation(msg.s);
  }

  //***************************************************************************
  /*
  * Router forwarded a unkonwn message.
  */
  void on_receive_unknown(const etl::imessage& msg)
  {
    std::cout << "  Received unknown message " << int(msg.get_message_id()) << std::endl;
  }

private:

  etl::queue<message_packet, 10> queue;
};