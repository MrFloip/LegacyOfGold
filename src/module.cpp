#include <iostream>
#include <fstream>
#include "module.h"
#include "graphics.h"
#include "level.h"

Module::Module()
{
	pos_x = pos_y = 0;
	running = false;
	l = new Level();
	std::ofstream os;
	os.open("the_output.txt");
	os << *l;
	os.close();
}

Module::~Module()
{
	delete l;
}

void Module::start(Graphics *graphics)
{
	graphics->setTitle("is running: Module");
	running = true;
}

bool Module::isRunning()
{
	return running;
}

void Module::onEvent(const SDL_Event & event)
{
	switch(event.type)
	{
	case SDL_KEYDOWN:
		onKeyDown(event.key.keysym.sym, event.key.keysym.mod, event.key.keysym.unicode);
		break;
	case SDL_KEYUP:
		onKeyUp(event.key.keysym.sym, event.key.keysym.mod, event.key.keysym.unicode);
		break;
	case SDL_MOUSEMOTION:
		onMouseMove(event.motion.x, event.motion.y, event.motion.xrel, event.motion.yrel,
			event.motion.state & SDL_BUTTON(SDL_BUTTON_LEFT),
			event.motion.state & SDL_BUTTON(SDL_BUTTON_RIGHT),
			event.motion.state & SDL_BUTTON(SDL_BUTTON_MIDDLE));
		break;
	case SDL_JOYAXISMOTION:
		onJoyAxis(event.jaxis.which, event.jaxis.axis, event.jaxis.value);
		break;
	case SDL_JOYBALLMOTION:
		onJoyBall(event.jball.which, event.jball.ball, event.jball.xrel, event.jball.yrel);
		break;
	case SDL_JOYHATMOTION:
		onJoyHat(event.jhat.which, event.jhat.hat, event.jhat.value);
		break;
	case SDL_JOYBUTTONDOWN:
		onJoyButtonDown(event.jbutton.which, event.jbutton.button);
		break;
	case SDL_JOYBUTTONUP:
		onJoyButtonUp(event.jbutton.which, event.jbutton.button);
		break;
	 case SDL_VIDEORESIZE:
	 	onResize(event.resize.w, event.resize.h);
	 	break;
		//case ...
		default:
		break;
	}
}

void Module::onOpen()
{
}

void Module::onClose()
{
}

void Module::onLoop()
{
}

void Module::onUpdate(Graphics *graphics)
{
	graphics->clear(0x115588);

	SDL_Rect temp;
	temp.x = pos_x-16;
	temp.y = pos_y-16;
	temp.w = 32;
	temp.h = 32;
	graphics->draw(temp, SDL_MapRGB(SDL_GetVideoSurface()->format, rand()%255, rand()%255, rand()%255));
	graphics->draw(l);
	graphics->update();
}

void Module::onSecond(long long int framespersecond)
{
}

void Module::onKeyDown(SDLKey key, SDLMod mod, Uint16 unicode)
{
}
void Module::onKeyUp(SDLKey key, SDLMod mod, Uint16 unicode)
{
}
void Module::onMouseMove(int x, int y, int relx, int rely, bool left, bool right, bool middle)
{
	pos_x = x;
	pos_y = y;
}
void Module::onMouseWheel(bool up)
{
}
void Module::onJoyAxis(Uint8 which, Uint8 axis, Sint16 value)
{
}
void Module::onJoyButtonDown(Uint8 which, Uint8 button)
{
}
void Module::onJoyButtonUp(Uint8 which, Uint8 button)
{
}
void Module::onJoyHat(Uint8 which, Uint8 hat, Uint8 value)
{
}
void Module::onJoyBall(Uint8 which, Uint8 ball, Sint16 relx, Sint16 rely)
{
}

void Module::onResize(int width, int height)
{
}

void Module::onExit()
{
	running = false;
}
void Module::onCommand(std::string command, std::vector<std::string> arguments)
{
	std::cout << command << "was received.\n";
}