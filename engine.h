#ifndef ENGINE_H
#define ENGINE_H
#include <string>
#include <vector>
#include <SDL/SDL.h>

class Module;
class Graphics;

class Engine
{
public:
	Engine();
	~Engine();

	void runModule(Module *module);
	//void manage(LinkedModule *module)

	void runCommand(std::string command, std::vector<std::string> arguments);
private:
	Module *current;
	Graphics *graphics;		//graphics can either be SDL or OpenGL, SDL is always used for input
	SDL_Event event;
};

#endif