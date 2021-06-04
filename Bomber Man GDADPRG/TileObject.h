#pragma once
#include "AGameObject.h"
class TileObject : public AGameObject
{
public:
	enum  TileType
	{
		Walkable = 0, Destructible = 1, Block = 2, Portal = 3
	};

	TileObject(string name, TileType tileType, Vector2i coords);
	~TileObject();
	TileObject::TileType GetTileType();
	Vector2i GetCoords();

	void initialize();
private:

	TileType tileType;
	Vector2i coords;


};

