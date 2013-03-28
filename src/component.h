#ifndef COMPONENT_H
#define COMPONENT_H
#include <list>

class EventMessage;

using EventContainer 	= std::list<EventMessage*>;
using ComponentIdType	= unsigned int;
const ComponentIdType	COMPONENT_NO_ID	= 0;

class Component
{
public:
	Component();
	virtual ~Component();
	virtual void Startup() = 0;
	virtual void Update() = 0;
	virtual void Shutdown() = 0;
	EventContainer getEvents();
	void handleEvents(const EventContainer *_events);
private:
	ComponentIdType id;
	virtual void readEvent(EventMessage *event) = 0;
	void addEvent(EventMessage *event);
	EventContainer events;
};

#endif