#include "linked_module.h"

LinkedModule::LinkedModule() : Module()
{
}

LinkedModule::~LinkedModule()
{
}

bool LinkedModule::isDead()
{
	return dead;
}

LinkedModule* LinkedModule::nextModule()
{
	return next;
}