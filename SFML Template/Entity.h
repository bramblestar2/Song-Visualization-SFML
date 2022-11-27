#pragma once
#include "Dynamic.h"

class Entity : public Dynamic
{
public:
	Entity(std::string _Type, sf::Vector2f _Position);
	Entity(std::string _Type);
	Entity();
	~Entity();

	bool isPlayer();
	/// <summary>
	///	Damages the entity by a certain amount
	/// </summary>
	/// <returns>Returns the amount of health is left on the entity</returns>
	int damageEntity(const int _Damage);

	sf::Vector2f getPosition() const;
	int getDamage() const;
	int getHealth() const;
	int getMaxHealth() const;
	sf::Vector2f getVelocity() const;
protected:
	void setPosition(sf::Vector2f _New_Position);
	void setPosition(const float _X, const float _Y);
	//Set the amount of damage the entity will inflict
	void setDamage(const int _Damage);
	void setMaxHealth(const int _Health);
	void setVelocity(sf::Vector2f _Velocity);

	virtual void move() = 0;

private:
	sf::Vector2f velocity;
	sf::Vector2f position;
	int maxHealth;
	int health;
	int damage;
};
