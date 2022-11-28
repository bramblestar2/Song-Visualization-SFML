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
	Entity::setMaxHealth(10);
}

Player::~Player()
{
}

void Player::setPlayArea(sf::FloatRect _Play_Area)
{
	playArea = _Play_Area;
}

bool Player::insidePlayArea(const sf::Vector2f _Position) const
{
	return playArea.contains(_Position);
}

int Player::getLives() const
{
	return lives;
}

bool Player::lostLife() const
{
	return Entity::getHealth() < 0;
}

bool Player::hasDied() const
{
	return lives < 0;
}

void Player::update()
{
	gif.update(sPlayer);
}

void Player::render(sf::RenderTarget& window)
{
}

void Player::setGif(const std::string _Folder, const std::string _Format, const std::string _FileExtension, const int _FrameCount, const int _StartFrame)
{
	gif = Gif(_Folder, _Format, _FileExtension, _FrameCount, _StartFrame);
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
	if (sf::Keyboard::isKeyPressed(moveKeys.up))
	{ }
	if (sf::Keyboard::isKeyPressed(moveKeys.down))
	{ }
	if (sf::Keyboard::isKeyPressed(moveKeys.left))
	{ }
	if (sf::Keyboard::isKeyPressed(moveKeys.right))
	{ }
}
