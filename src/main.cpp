#include "engine.h"
#include "module.h"
#include <iostream>
#include <vector>
#include <string>
#include <SDL/SDL.h>

using namespace std;

int main(int argc, char *argv[])
{
	Engine *E = new Engine();
	E->runModule( new Module() );
	delete E;
	return 0;
}