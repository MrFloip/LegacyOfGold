#ifndef GRAPHICS_H
#define GRAPHCIS_H
#include <SDL\SDL.h>
#include <string>

class Level;

class Graphics
{
public:
	Graphics();
	virtual ~Graphics();
	void draw(SDL_Surface *sprite, SDL_Rect &clip, int color_key = 0xFF00FF);
	void draw(SDL_Rect &box, int color);
	void draw_tile(int id, int x, int y);
	void clear(int color);
	void setTitle(std::string new_title);
	void update();
	void draw(Level *level);
private:
	void load_tiles(std::string filename);
	SDL_Surface *tileset;
	int width;
	int height;
	int bpp;
	std::string title;
	SDL_Surface *screen;
};

#endif