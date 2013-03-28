#include "event_message.h"
#include "component.h"

EventMessage::EventMessage(std::string _event_type, std::string _message_data, ComponentIdType _owner_id, ComponentIdType _target_id)
	: event_type(_event_type), message_data(_message_data), owner_id(_owner_id), target_id(_target_id)
{
}

EventMessage::~EventMessage()
{
}