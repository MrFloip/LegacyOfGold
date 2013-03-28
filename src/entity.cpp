#include "entity.h"
#include "component.h"
#include "event_message.h"
#include <algorithm>

using namespace std;

Entity::Entity()
{
	
}

Entity::~Entity()
{
	for(auto rit = components.rbegin(); rit != components.rend(); ++rit)
	{
		delete (*rit);
	}
	components.clear();
	if(events != nullptr)
	{
		for(auto rit = (*events).rbegin(); rit != (*events).rend(); ++rit)
		{
			delete (*rit);
		}
		events->clear();
		events = nullptr;
	}
}

void Entity::update()
{
	//mata varje component med events
	for(Component* C : components)
	{
		C->handleEvents( events );
	}
	//ta bort alla events i entity
	if(events != nullptr)
	{
		for(auto rit = (*events).rbegin(); rit != (*events).rend(); ++rit)
		{
			delete (*rit);
		}
		events->clear();
	}
	else
		events = new EventContainer;
	//kopiera events från alla componenters buffrar till entitys events
	for(Component* C : components)
	{
		EventContainer e = C->getEvents();
		copy(e.begin(), e.end(), events->end()); 
	}
}