#ifndef COMPONENT_TILE_POSITION_H
#define COMPONENT_TILE_POSITION_H
#include "component.h"

class ComponentTilePosition : public Component
{
public:
	ComponentTilePosition();
	virtual ~ComponentTilePosition();
	void Startup();
	void Update();
	void Shutdown();
private:
	void readEvent(EventMessage *event);
	int x;
	int y;
	int height;
	double trans_x;	//-1 <> 1
	double trans_y;	//-1 <> 1
};

#endif