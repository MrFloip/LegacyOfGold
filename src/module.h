#ifndef MODULE_H
#define MODULE_H
#include <SDL\SDL.h>
#include <string>
#include <vector>

class Graphics;
class Level;

class Module
{
public:
	friend class Engine;

	Module();
	virtual ~Module();

	void start(Graphics *graphics);

	void onEvent(const SDL_Event & event);
	bool isRunning();

	virtual void onOpen();
	virtual void onClose();
	virtual void onLoop();
	virtual void onUpdate(Graphics *graphics);
	virtual void onSecond(long long int framespersecond);

	virtual void onKeyDown(SDLKey key, SDLMod mod, Uint16 unicode);
	virtual void onKeyUp(SDLKey key, SDLMod mod, Uint16 unicode);
	virtual void onMouseMove(int x, int y, int relx, int rely, bool left, bool right, bool middle);
	virtual void onMouseWheel(bool up);
	virtual void onJoyAxis(Uint8 which, Uint8 axis, Sint16 value);
	virtual void onJoyButtonDown(Uint8 which, Uint8 button);
	virtual void onJoyButtonUp(Uint8 which, Uint8 button);
	virtual void onJoyHat(Uint8 which, Uint8 hat, Uint8 value);
	virtual void onJoyBall(Uint8 which, Uint8 ball, Sint16 relx, Sint16 rely);

	virtual void onResize(int width, int height);
	virtual void onExit();
	virtual void onCommand(std::string command, std::vector<std::string> arguments);

private:
	Level *l;
	int pos_x;
	int pos_y;
	bool running;
};

#endif
