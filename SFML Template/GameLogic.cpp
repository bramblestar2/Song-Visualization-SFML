#include "GameLogic.h"

GameLogic::GameLogic()
{
	objects.push_back(new Player());
}

GameLogic::~GameLogic()
{
	for (int i = 0; i < objects.size(); i++)
		delete objects.at(i);
}

sf::RenderTexture& GameLogic::renderPlayer(sf::Vector2f _Draw_Size)
{
	sf::ContextSettings settings;
	sf::RenderTexture* rendering = new sf::RenderTexture;
	rendering->create(_Draw_Size.x, _Draw_Size.y, settings);
	rendering->clear(sf::Color(0, 0, 0, 0));


	for (int i = 0; i < objects.size(); i++)
	{
		if (objects.at(i)->getType() == "Player")
		{
			objects.at(i)->render(*rendering);
		}
	}

	return *rendering;
}
