#pragma once
#include "Entity.h"
#include "Gif.h"

class Player : public Entity
{
public:
	Player();
	~Player();

	//Area that the player will be locked inside of
	void setPlayArea(sf::FloatRect _Play_Area);

	bool insidePlayArea(const sf::Vector2f _Position) const;
	int getLives() const;
	bool lostLife() const;
	bool hasDied() const;

	void update() override;
	void render(sf::RenderTarget& window) override;

	void setGif(const std::string _Folder, const std::string _Format, const std::string _FileExtension, const int _FrameCount, const int _StartFrame);

protected:
	//returns true if player is out of bounds
	bool outBounds();
	void setLives(const int _Lives);

	void move() override;

private:
	int lives;
	sf::FloatRect playArea;
	
	sf::RectangleShape sPlayer;
	Gif gif;

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

