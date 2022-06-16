#include "../include/datarouter.hpp"
#include "spdlog/spdlog.h"

// using namespace sqlite_orm;

// auto db = make_storage("constellations.sqlite",
//                        make_table("SERDE_CONSTELLATIONS",
//                                   make_column("ID", &Cached_Constellation::id, primary_key()),
//                                   make_column("BLOB", &Cached_Constellation::blob)));

//*****************************************************************************
// The message router.
// Handles message types ConstellationRequestMsg, Message2, ConstellationCreateMsg.
//***************************************************************************
// Override the base class's receive function.
void Router::receive(const etl::imessage &msg_)
{
  if (accepts(msg_))
  {
    // Place in queue.
    queue.emplace(msg_);
  spdlog::info("Routing message. Its type is {} ",int(msg_.get_message_id()));
  }
  else
  {
    spdlog::info("Ignoring message, no route available. Its id is{}",int(msg_.get_message_id()));
  }
}

//***************************************************************************
void Router::process_queue()
{
  while (!queue.empty())
  {
    message_packet &packet = queue.front();
    etl::imessage &msg = packet.get();
    spdlog::info("Forwarding message to its handler. Its id is {}",int(msg.get_message_id()));

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
void Router::on_receive(const ConstellationRequestMsg &msg)
{
  // for (auto &serialized_constellation : db.iterate<Cached_Constellation>())
  // {
  //   std::cout << db.dump(serialized_constellation) << std::endl;
  // }
}

//***************************************************************************
void Router::on_receive(const Message2 &msg)
{
  spdlog::info("Received unimplemented message {},{}",int(msg.get_message_id()),msg.d);
}

//***************************************************************************
/*
 * Add new constellation to the database
 */
void Router::on_receive(const ConstellationCreateMsg &msg)
{
 spdlog::info("Received a Constellation Create message ID {},{} ",int(msg.get_message_id()),msg.s);
//  db.insert( Cached_Constellation{ -1,msg.s});
}

//***************************************************************************
/*
 * Router forwarded a unkonwn message.
 */
void Router::on_receive_unknown(const etl::imessage &msg)
{
  spdlog::info("Received unknown message {}",int(msg.get_message_id()));
}

void Router::init_storage()
{
//  db.sync_schema();
//  db.remove_all<Cached_Constellation>();
}