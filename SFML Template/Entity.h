#pragma once
#include "Dynamic.h"

class Entity : public Dynamic
{
public:
	Entity(std::string _Type, sf::Vector2f _Position);
	Entity(std::string _Type);
	Entity();
	~Entity();

	sf::Vector2f getPosition() const;
	bool isPlayer();
	/// <summary>
	///	Damages the entity by a certain amount
	/// </summary>
	/// <returns>Returns the amount of health is left on the entity</returns>
	int damageEntity(const int _Damage);

	int getDamage() const;

	//void update() override;
	//void render(sf::RenderWindow& _Window) override;
protected:
	void setPosition(sf::Vector2f _New_Position);
	void setPosition(const float _X, const float _Y);
	//Set the amount of damage the entity will inflict
	void setDamage(const int _Damage);
	void setHealth(const int _Health);

	virtual void move() = 0;

private:
	sf::Vector2f position;
	int health;
	int damage;
};
