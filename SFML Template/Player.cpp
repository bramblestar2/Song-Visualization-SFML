#include "Player.h"

Player::Player() : Entity("Player")
{
	moveKeys = {
		sf::Keyboard::Up,
		sf::Keyboard::Down,
		sf::Keyboard::Left,
		sf::Keyboard::Right,
	};

	actionKeys = {
		sf::Keyboard::Space,
		sf::Keyboard::Z
	};


	setLives(3);
	Entity::setDamage(1);
	Entity::setHealth(10);
}

Player::~Player()
{
}

void Player::setPlayArea(sf::FloatRect _Play_Area)
{
	playArea = _Play_Area;
}

int Player::getLives() const
{
	return lives;
}

void Player::update()
{
}

void Player::render(sf::RenderTarget& window)
{
}

bool Player::outBounds()
{
	sf::Vector2f pos = Entity::getPosition();

	return !playArea.contains(pos);
}

void Player::setLives(const int _Lives)
{
	lives = _Lives;
}

void Player::move()
{
	
}
