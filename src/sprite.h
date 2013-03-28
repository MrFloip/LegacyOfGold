#ifndef SPRITE_H
#define SPRITE_H
#include "xml_reader.h"
#include <vector>
#include <string>
#include <map>

using anim_rects = std::vector<SDL_Rect>;

class Sprite
{
public:
	Sprite();
	~Sprite();
	bool setAnimation(std::string new_anim_state);
	void setPos(int new_x, int new_y);
	friend XmlReader & operator>>(XmlReader & reader, const Sprite & sprite);//read
	friend XmlReader & operator<<(XmlReader & reader, const Sprite & sprite);//write
private:
	std::map<std::string, anim_rects> anim_data;//each element is a different animation
	std::string anim_state;
	int color_key;
	int x;
	int y;
};

#endif
