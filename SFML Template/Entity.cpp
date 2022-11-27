#include "Entity.h"

Entity::Entity(std::string _Type, sf::Vector2f _Position) : Dynamic(_Type)
{
	setPosition(_Position);

	setHealth(0);
	setDamage(0);
}

Entity::Entity(std::string _Type) : Dynamic(_Type)
{
	setHealth(0);
	setDamage(0);
}

Entity::Entity() : Dynamic("Entity")
{
	setHealth(0);
	setDamage(0);
}

Entity::~Entity()
{
}

sf::Vector2f Entity::getPosition() const
{
	return position;
}

bool Entity::isPlayer()
{
	if (Dynamic::getType() == "Player")
		return true;
	return false;
}

int Entity::damageEntity(const int _Damage)
{
	health -= _Damage;
	return health;
}

int Entity::getDamage() const
{
	return damage;
}

void Entity::setPosition(sf::Vector2f _New_Position)
{
	position = _New_Position;
}

void Entity::setPosition(const float _X, const float _Y)
{
	position = sf::Vector2f(_X, _Y);
}

void Entity::setDamage(const int _Damage)
{
	damage = _Damage;
}

void Entity::setHealth(const int _Health)
{
	health = _Health;
}
