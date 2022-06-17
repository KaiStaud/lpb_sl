/**
 * @file datarouter.hpp
 * @author Kai Staud
 * @brief  Route messages / queues between mutiple program entities.
  Constellations / Stars / Tracks are forwareded between db and tracking logic.
  The router also has access to the MQTT Client to receive messages from outside.
 
 * @version 0.1
 * @date 2022-05-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "etl/queue.h"
#include "etl/message_router.h"

#include <iostream>
#include <string>

struct Cached_Constellation{
//    int id;
    std::string blob;
};

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
  ConstellationCreateMsg(const std::string &s_)
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

  Router() : message_router(1)
  {
  }

  //***************************************************************************
  // Override the base class's receive function.
  void receive(const etl::imessage &msg_);
  void process_queue();
  void on_receive(const ConstellationRequestMsg &msg);
  void on_receive(const Message2 &msg);
  void on_receive(const ConstellationCreateMsg &msg);
  void on_receive_unknown(const etl::imessage &msg);

private:
  etl::queue<message_packet, 10> queue;
  void init_storage();
};