#pragma once
#include "Player.h"
#include <vector>

class GameLogic
{
public:
	GameLogic();
	~GameLogic();

	sf::RenderTexture& renderPlayer(sf::Vector2f _Draw_Size);

private:
	std::vector<Dynamic*> objects;
};

