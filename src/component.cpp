#include "component.h"
#include "event_message.h"

using namespace std;

Component::Component()
{
}

Component::~Component()
{
}

void Component::handleEvents(const EventContainer *_events)
{
	//ta bort events först
	for(auto it = _events->cbegin(); it != _events->cend(); ++it)
	{
		readEvent(*it);
	}
}

EventContainer Component::getEvents()
{
	return events;
}

void Component::addEvent(EventMessage *event)
{
	events.push_back(event);
}