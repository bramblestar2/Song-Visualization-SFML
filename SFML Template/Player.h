#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	Player();
	~Player();

	//Area that the player will be locked inside of
	void setPlayArea(sf::FloatRect _Play_Area);

	int getLives() const;

	void update() override;
	void render(sf::RenderTarget& window) override;

protected:
	//returns true if player is out of bounds
	bool outBounds();
	void setLives(const int _Lives);

	void move() override;

private:
	sf::FloatRect playArea;
	
	int lives;

	struct MovementKeys
	{
		sf::Keyboard::Key up;
		sf::Keyboard::Key down;
		sf::Keyboard::Key left;
		sf::Keyboard::Key right;
	};

	struct ActionKeys
	{
		sf::Keyboard::Key fire;
		sf::Keyboard::Key ability;
	};

	union
	{
		MovementKeys moveKeys;
		ActionKeys actionKeys;
	};
};

