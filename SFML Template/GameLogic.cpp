#include "GameLogic.h"

GameLogic::GameLogic()
{
	objects.push_back(new Player());
	addSprite(Gif("Sprites/Player/", "frame (#)", ".png", 1, 1), "Player", sf::seconds(1000000));
	
	initGraphics();
}

GameLogic::~GameLogic()
{
	for (int i = 0; i < objects.size(); i++)
		delete objects.at(i);
}

void GameLogic::renderPlayer(sf::Vector2f _Draw_Size, sf::RenderTarget& _Window)
{
	for (int i = 0; i < objects.size(); i++)
	{
		if (objects.at(i)->getType() == "Player")
		{
			objects.at(i)->render(_Window);
		}
	}
}

void GameLogic::renderEnemies(sf::Vector2f _Draw_Size, sf::RenderTarget& _Window)
{
	for (int i = 0; i < objects.size(); i++)
	{
		if (objects.at(i)->getType() == "Enemy")
		{
			objects.at(i)->render(_Window);
		}
	}
}

void GameLogic::renderBullets(sf::Vector2f _Draw_Size, sf::RenderTarget& _Window)
{
	for (int i = 0; i < objects.size(); i++)
	{
		if (objects.at(i)->getType() == "Bullet")
		{
			objects.at(i)->render(_Window);
		}
	}
}

void GameLogic::initGraphics()
{
	for (int i = 0; i < objects.size(); i++)
	{
		std::string type = objects.at(i)->getType();
		if (type == "Player")
		{
			for (int k = 0; k < sprites.size(); k++)
			{
				if (sprites.at(i)->getType() == type)
				{
					Gif* gif = sprites.at(k).get();
					((Entity*)objects.at(i))->setGif(gif);
				}
			}
		}
	}
}

void GameLogic::addSprite(Gif _Gif, const std::string _Type, const sf::Time _Time)
{
	std::unique_ptr<Gif> sprite;
	sprite.reset(&_Gif);
	sprite->setFrameTime(_Time);
	sprite->setType(_Type);

	sprites.push_back(sprite);
}

void GameLogic::update()
{
	for (int i = 0; i < objects.size(); i++)
	{
		objects.at(i)->update();
	}
}