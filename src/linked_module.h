#ifndef LINKED_MODULE_H
#define LINKED_MODULE_H
#include "module.h"

class LinkedModule : public Module
{
public:
	LinkedModule();
	virtual ~LinkedModule();

	bool isDead();
	LinkedModule* nextModule();
private:
	LinkedModule* next;
	bool dead;
};

#endif