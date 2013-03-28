#include "engine.h"
#include "module.h"
#include "graphics.h"

Engine::Engine()
{
	SDL_Init( SDL_INIT_EVERYTHING );
	graphics = new Graphics();
}

Engine::~Engine()
{
	delete graphics;
	SDL_Quit();
}

void Engine::runModule(Module *module)
{
	current = module;
	//todo: have FPS
	module->start(graphics);
	module->onOpen();
	while(module->isRunning())
	{
		SDL_PollEvent(&event);
		if(event.type == SDL_QUIT)
			module->onExit();
		module->onEvent(event);
		module->onLoop();
		module->onUpdate(graphics);
		//module->onSecond()
	}
	module->onClose();
}

void Engine::runCommand(std::string command, std::vector<std::string> arguments)
{
	if(current != NULL)
	{
		current->onCommand(command, arguments);
	}
}