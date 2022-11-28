#pragma once
#include "Dynamic.h"

class Bullet : public Dynamic
{
public:
	Bullet();
	~Bullet();

	void update() override;
	void render(sf::RenderTarget& window) override;

private:

};