#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>


class Dynamic
{
public:
	Dynamic(std::string _Type);
	~Dynamic();

	virtual void update() = 0;
	virtual void render(sf::RenderTarget& window) = 0;

	std::string getType() const { return type; }

protected:
	float lerp(float a, float b, float t);

private:

	std::string type;
};

