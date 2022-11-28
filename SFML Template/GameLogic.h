#pragma once
#include "Player.h"
#include <vector>
#include <memory>

class GameLogic
{
public:
	GameLogic();
	~GameLogic();

	void renderPlayer(sf::Vector2f _Draw_Size, sf::RenderTarget& _Window);
	void renderEnemies(sf::Vector2f _Draw_Size, sf::RenderTarget& _Window);
	void renderBullets(sf::Vector2f _Draw_Size, sf::RenderTarget& _Window);

	void update();

private:
	void initGraphics();
	void addSprite(Gif _Gif, const std::string _Type, const sf::Time _Time);
	std::vector<std::unique_ptr<Gif>> sprites;

	std::vector<Dynamic*> objects;
};

