#ifndef ENTITY_H
#define ENTITY_H
#include <string>
#include <vector>
#include <list>

class Component;
class EventMessage;

using ComponentContainer 	= std::vector<Component*>;
using EventContainer 		= std::list<EventMessage*>;

class Entity
{
public:
	Entity();
	~Entity();
	void attachComponent(Component * comp);	//, ...)
	void detachComponent(std::string component_name);
	void receiveEvent(EventMessage event);
	void update();
private:
	EventContainer*		events;
	ComponentContainer	components;
};

#endif