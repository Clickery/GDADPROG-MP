#include "TileMap.h"
#include "TileObject.h"
#include "GameObjectManager.h"
TileMap::TileMap()
{
}

TileMap::~TileMap()
{
}

void TileMap::initialize()
{
	srand(time(NULL));

	//initialize blocks an walkables 
	int distructiblePlaced = 0;
	for (int i = 0; i < this->GRID_SIZE; i++)
	{
		vector<TileObject*> temp;
		for (int j = 0; j < this->GRID_SIZE; j++)
		{
			TileObject* tile = nullptr;
			if (j == 0 || j == this->GRID_SIZE - 1 || (j % 2 == 0 && i % 2 == 0) || i == 0 || i == this->GRID_SIZE - 1)
			{ 
				tile = new TileObject("tile_block", TileObject::Block, Vector2i(j, i));
			}
			else
			{
				tile = new TileObject("tile_walkable", TileObject::Walkable, Vector2i(j, i));

			}
			temp.push_back(tile);
		}
		this->map.push_back(temp);
	}

	
	//initialize destructible
	vector<Vector2i> walkableCoords;
	for (int i = 0; i < this->GRID_SIZE; i++)
	{
		for (int j = 0; j < this->GRID_SIZE; j++)
		{
			if (this->map[j][i]->GetTileType() == TileObject::Walkable)
			{
				walkableCoords.push_back(Vector2i(j, i));
			}
		}
	}

	int placedDestructible = 0;
	int randIndex = 0;
	int placePortal = 0;
	while (placedDestructible < this->DISTRUCTIBLE_SIZE)
	{
		randIndex = rand() % walkableCoords.size();
		if (walkableCoords[randIndex].x > 3 || walkableCoords[randIndex].y > 3)
		{
			TileObject* tile = new TileObject("tile_destructible", TileObject::Destructible, walkableCoords[randIndex]);
			this->destuctibles.push_back(tile);
			placedDestructible++;
			if (placePortal < 1)
			{
				TileObject* tile = new TileObject("tile_portal", TileObject::Portal, walkableCoords[randIndex]);
				this->Portal = tile;
				placePortal++;
			}
			walkableCoords.erase(walkableCoords.begin() + randIndex);
		}
	}

	

	for (int i = 0; i < this->GRID_SIZE; i++)
	{
		for (int j = 0; j < this->GRID_SIZE; j++)
		{
			GameObjectManager::getInstance()->addObject(this->map[j][i]);
		}
	}

	GameObjectManager::getInstance()->addObject(this->Portal);

	for (int i = 0; i < this->DISTRUCTIBLE_SIZE; i++)
	{
		GameObjectManager::getInstance()->addObject(this->destuctibles[i]);
		//static_cast<TileObject*>(GameObjectManager::getInstance()->findObjectByName("tile"));
	}

	
}