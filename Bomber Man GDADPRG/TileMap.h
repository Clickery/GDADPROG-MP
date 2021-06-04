#pragma once
#include "TileObject.h"
class TileMap
{
public:
	TileMap();
	~TileMap();

	void initialize();
private:

	int const GRID_SIZE = 13;
	int const DISTRUCTIBLE_SIZE = 25;
	vector<vector<TileObject*>> map;
	vector<TileObject*> destuctibles;
	TileObject* Portal;
};

