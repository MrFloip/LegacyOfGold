#ifndef LEVEL_H
#define LEVEL_H
#include <vector>
#include <iostream>
#include <string>

struct tile
{
	short 		height;
	unsigned 	data;
	tile*		next;

	tile(short height, unsigned data, tile* next = nullptr)
	{
		this->height = height;
		this->data = data;
		this->next = next;
	}
};

int getPos(int x, int y, int w, int h);

class Level
{
	friend class Graphics;
private:
	std::string name;
	unsigned int width;
	unsigned int height;
	std::vector<tile*> tiles;
	void delete_tile(tile * t);
public:
	bool load(std::string filename);

	unsigned getTileData(int x, int y, int h);
	tile* getLowestTile(int x, int y);

	friend std::ostream & operator<<(std::ostream & lhs, Level & rhs);
	//friend XmlReader & operator>>(XmlReader & lhs, Level & rhs);

	Level();
	~Level();
};

#endif