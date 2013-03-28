#ifndef EVENT_MESSAGE_H
#define EVENT_MESSAGE_H
#include <string>
#include "component.h"

class EventMessage
{
public:
	EventMessage(std::string _event_type, std::string _message_data, ComponentIdType _owner_id, ComponentIdType _target_id = COMPONENT_NO_ID);
	~EventMessage();
private:
	std::string event_type;
	std::string message_data;
	ComponentIdType owner_id;
	ComponentIdType target_id;
};

#endif