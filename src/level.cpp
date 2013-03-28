#include "level.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "tinyxml2.h"

Level::Level()
	: width(8), height(8)
{

	srand(time(NULL));
	tile * temp;
	for(int i=0;i<8;++i)
	{
		for(int j=0;j<8;++j)
		{
			temp = new tile( 0, rand()%36);
			if(rand()%2 == 0)
			{
				temp->next = new tile(rand()%4 + 1, rand()%36);
			}
			tiles.push_back( temp );
		}
	}
	name = "Generated area";
	load("level.level");
}

void Level::delete_tile(tile *t)
{
	if(t == nullptr)
		return;
	else if(t->next == nullptr)
	{
		delete t;
		return;
	}
	else
		delete_tile(t->next);
}

Level::~Level()
{
	for(auto rit = tiles.rbegin(); rit != tiles.rend(); ++rit)
	{
		tile *t = (*rit);
		delete_tile(t);
	}
	tiles.clear();
}

int getPos(int x, int y, int w, int h)
{
	if(y*w + x <= w*h)
		return y*w + x;
	else
		return -1;
}

unsigned Level::getTileData(int x, int y, int h)
{
	tile *t = getLowestTile(x, y);
	while(t->next != nullptr)
	{
		if(t->height == h)
			return t->data;
		t = t->next;
	}
	return 0;	//0 is no colission, no image, aka air
}

tile* Level::getLowestTile(int x, int y)
{
	return tiles.at(getPos(x, y, width, height));
	//throws an out of range exception
}

bool Level::load(std::string filename)
{
	using namespace tinyxml2;
	XMLDocument doc;
	if(doc.LoadFile( filename.c_str() ) != XML_NO_ERROR)
		return false;

	const char *c = doc.RootElement()->FirstChildElement("level")->Attribute("title");
	name = c;
	std::ofstream lol;
	lol.open("hah.txt");
	lol << name;
	lol.close();
	return true;
}

std::ostream & operator<<(std::ostream & lhs, Level & rhs)
{
	int i = 0;
	for(tile * t : rhs.tiles)
	{
		if(i%rhs.width == 0)
			lhs << std::endl;

		lhs << t->height << ":" << t->data;
		if(t->next != nullptr)
			lhs << "^";
		else
			lhs << " ";

		++i;
	}
	lhs << std::endl;
	lhs << rhs.tiles.size();
}

/*XmlReader & operator>>(XmlReader & lhs, Level & rhs)
{

}*/