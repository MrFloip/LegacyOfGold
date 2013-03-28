#include "graphics.h"
#include "level.h"

Graphics::Graphics()
	: width(480), height(360), bpp(32), title("mojam2")
{
	screen = SDL_SetVideoMode(width, height, bpp, SDL_HWSURFACE);
	SDL_WM_SetCaption(title.c_str(), NULL);
	load_tiles("stone_temple2.bmp");
}

void Graphics::load_tiles(std::string filename)
{
	SDL_Surface* loaded_image = NULL;
	SDL_Surface* optimized_image = NULL;
	loaded_image = SDL_LoadBMP(filename.c_str());
	if(loaded_image != NULL)
	{
		optimized_image = SDL_DisplayFormat(loaded_image);
		SDL_FreeSurface(loaded_image);
	}
	if(optimized_image != NULL)
	{
		Uint32 colorkey = SDL_MapRGB( optimized_image->format, 0xFF, 0, 0xFF);
		SDL_SetColorKey( optimized_image, SDL_SRCCOLORKEY, colorkey);
	}
	tileset = optimized_image;
}

void Graphics::draw_tile(int id, int x, int y)
{
	SDL_Rect offset;
	offset.x = x*32;
	offset.y = y*32;
	SDL_Rect clip;
	clip.x = (id%6)*32;
	clip.y = ((int)(id/6))*32;
	clip.w = 32;
	clip.h = 32;
	SDL_BlitSurface(tileset, &clip, screen, &offset);
}

Graphics::~Graphics()
{
	SDL_FreeSurface(tileset);
}

void Graphics::setTitle(std::string new_title)
{
	title = new_title;
	SDL_WM_SetCaption(title.c_str(), NULL);
}

void Graphics::draw(SDL_Surface *sprite, SDL_Rect &clip, int color_key)
{
}

void Graphics::draw(SDL_Rect &box, int color)
{
	SDL_FillRect(screen, &box, color);
}

void Graphics::draw(Level *level)
{
	SDL_Rect temp;
	temp.w = 8;
	temp.h = 8;
	temp.x = 0;
	temp.y = 0;

	for(int y = 0; y < level->height ; ++y)
	{
		for(int x = 0; x < level->width ; ++x)
		{
			tile *t = level->tiles[y*level->width + x];
			if(t != nullptr) draw_tile(t->data, x, y);
			int i = 0;
			while(t->next != nullptr)
			{
				i += t->next->height-t->height;
				t = t->next;
				draw_tile(t->data, x, y);
			}
		}
	}
}

void Graphics::clear(int color)
{
	SDL_FillRect(screen, NULL, color);
}

void Graphics::update()
{
	SDL_Flip(screen);
}