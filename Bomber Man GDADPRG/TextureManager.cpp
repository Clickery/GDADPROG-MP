#include "TextureManager.h"

using namespace std;
using namespace sf;

TextureManager* TextureManager::sharedInstance = NULL;

TextureManager* TextureManager::getInstance()
{
	if (sharedInstance == NULL) {
		sharedInstance = new TextureManager();
	}

	return sharedInstance;
}

void TextureManager::loadAll()
{
	/* SPRITES */
	
	sf::Texture* texture = new sf::Texture();

	string image = "Media/Textures/Bomberman/Back/Bman_B_f00.png";
	for (int i = 0; i < 8; i++)
	{
		texture = new sf::Texture();
		string string = to_string(i);
		char iterate = string[0];
		image[39] = iterate;
		texture->loadFromFile(image);
		this->textureMap[BomberManBack].push_back(texture);
	}
	
	
	image = "Media/Textures/Bomberman/Front/Bman_F_f00.png";
	for (int i = 0; i < 8; i++)
	{
		texture = new sf::Texture();
		string string = to_string(i);
		char iterate = string[0];
		image[40] = iterate;
		texture->loadFromFile(image);
		this->textureMap[BomberManFront].push_back(texture);
	}
	

	image = "Media/Textures/Bomberman/Right/Bman_R_f00.png";
	for (int i = 0; i < 8; i++)
	{
		texture = new sf::Texture();
		string string = to_string(i);
		char iterate = string[0];
		image[40] = iterate;
		texture->loadFromFile(image);
		this->textureMap[BomberManRight].push_back(texture);
	}


	image = "Media/Textures/Bomberman/Left/Bman_L_f00.png";
	for (int i = 0; i < 8; i++)
	{
		texture = new sf::Texture();
		string string = to_string(i);
		char iterate = string[0];
		image[39] = iterate;
		texture->loadFromFile(image);
		this->textureMap[BomberManLeft].push_back(texture);
	}
	
	
	image = "Media/Textures/Environment/BackgroundTile.png";
	texture = new sf::Texture();
	texture->loadFromFile(image);
	this->textureMap[WalkableGround].push_back(texture);

	image = "Media/Textures/Environment/ExplodableBlock.png";
	texture = new sf::Texture();
	texture->loadFromFile(image);
	this->textureMap[ExpodableBlock].push_back(texture);

	image = "Media/Textures/Environment/Portal.png";
	texture = new sf::Texture();
	texture->loadFromFile(image);
	this->textureMap[Portal].push_back(texture);

	image = "Media/Textures/Environment/SolidBlock.png";
	texture = new sf::Texture();
	texture->loadFromFile(image);
	this->textureMap[SolidBlock].push_back(texture);

	image = "Media/Textures/Menu/title_flat.jpg";
	texture = new sf::Texture();
	texture->loadFromFile(image);
	this->textureMap[MAIN_MENU_BG].push_back(texture);


	image = "Media/Textures/Buttons/play_button.png";
	texture = new sf::Texture();
	texture->loadFromFile(image);
	this->textureMap[ButtonNormal].push_back(texture);

	image = "Media/Textures/Buttons/play_button_pressed.png";
	texture = new sf::Texture();
	texture->loadFromFile(image);
	this->textureMap[ButtonPressed].push_back(texture);



	/*sf::Font* font = new sf::Font;
	if (font->loadFromFile("Media/Sansation.ttf"))
	{
		cout << "Font loaded Successfully!\n";
		this->fontMap[DefaultFont] = font;
	}*/

}

sf::Texture* TextureManager::getTextureAt(TextureManager::AssetType assetType, int index)
{
	if (!this->textureMap[assetType].empty()) {
		return this->textureMap[assetType][index];
	}

	else {
		cout << "No texture found for " << assetType << endl;;
		return NULL;
	}
}

int TextureManager::getTextureLength(TextureManager::AssetType assetType)
{
	if (!this->textureMap[assetType].empty()) {
		return this->textureMap[assetType].size();
	}

	else {
		cout << "No textures found for " << assetType << endl;
		return 0;
	}
}

sf::Font* TextureManager::getFont(FontType fontType)
{
	return this->fontMap[fontType];
}

void TextureManager::testFunction()
{
	cout << "Texture manager is a singleton!";
}