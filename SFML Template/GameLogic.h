#pragma once
#include "Player.h"
#include <vector>
#include <memory>

class GameLogic
{
public:
	GameLogic();
	~GameLogic();

	sf::RenderTexture& renderPlayer(sf::Vector2f _Draw_Size);
	sf::RenderTexture& renderEnemies(sf::Vector2f _Draw_Size);

private:
	std::vector<std::unique_ptr<Gif>> sprites;

	std::vector<Dynamic*> objects;
};

