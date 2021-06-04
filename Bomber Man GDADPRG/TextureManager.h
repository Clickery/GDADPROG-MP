#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <unordered_map>

using namespace std;

class TextureManager
{
public:
	enum AssetType { BG = 0, ButtonNormal = 1, ButtonPressed = 2, 
		BomberManFront = 3,  BomberManRight = 4, BomberManLeft = 5, BomberManBack = 6,
		WalkableGround = 7, ExpodableBlock = 8, SolidBlock = 9, Portal = 10, 
		MAIN_MENU_BG = 11};
	enum FontType { DefaultFont = 0 };
	static TextureManager* getInstance();
	void loadAll();
	sf::Texture* getTextureAt(TextureManager::AssetType assetType, int index);
	int getTextureLength(TextureManager::AssetType assetType);
	sf::Font* getFont(FontType fontType);
	void testFunction();

private:
	TextureManager() {};
	TextureManager(TextureManager const&);
	TextureManager& operator = (TextureManager const&) {};
	static TextureManager* sharedInstance;

	unordered_map<TextureManager::AssetType, vector<sf::Texture*>> textureMap;
	unordered_map<TextureManager::FontType, sf::Font*> fontMap;
};
