/**
 * @file datarouter.cpp
 * @author your name (you@domain.com)
 * @brief Implementation of Message Router, distributes iox messages
 * @version 0.1
 * @date 2022-05-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "../include/datarouter.hpp"
#include "../include/datahandling.hpp"
#include "spdlog/spdlog.h"

Datahandling::Storage db("test");

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
db.generic_insert("SERDE_CONSTELLATIONS",msg.s);
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