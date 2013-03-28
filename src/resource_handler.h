#ifndef RESOURCE_HANDLER_H
#define RESOURCE_HANDLER_H
#include <vector>
#include <string>
#include <map>
#include <SDL/SDL.h>

template <class ResType>
class ResourceCache
{
public:
	ResourceCache(std::string _path, int _max_resources);
	~ResourceCache();
	void trim();
	ResType * get(std::string filename);
	bool add(std::string filename);
private:
	std::map<std::string, *ResType> resources;
	std::string path;// for example "resources/music", adds to filename
	int max_resources;
};

class ResourceHandler
{
public:
	ResourceHandler();
	~ResourceHandler();
	SDL_Surface* getSurface(std::string filename);
	Sprite* getSprite(std::string filename);
	Mix_Music* getMusic(std::string filename);
	Mix_Chunk* getSound(std::string filename);
private:
	ResourceCache<SDL_Surface> SurfaceCache;
	ResourceCache<Sprite> SpriteCache;
	ResourceCache<Mix_Music> MusicCache;
	ResourceCache<Mix_Chunk> SoundCache;
	std::string resource_path;
};

#endif
