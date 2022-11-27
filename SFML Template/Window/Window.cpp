#include "Window.h"
#include "../Player.h"

Window::Window()
{
	initWindow();
	
}

Window::~Window()
{
	delete window;
}

void Window::run()
{
	while (window->isOpen())
	{
		update();
		updateDt();
		updateSFMLEvents();
		render();
	}
}

void Window::render()
{
	window->clear();


	sf::RenderTexture* players = &game.renderPlayer(sf::Vector2f(window->getSize()));
	window->draw(sf::Sprite(players->getTexture()));
	delete players;


	window->display();
}

void Window::update()
{
}

void Window::updateDt()
{
	dt = dtClock.restart().asSeconds();
}

void Window::updateSFMLEvents()
{
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed ||
			event.key.code == sf::Keyboard::Escape)
			window->close();
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
				window->close();
		}
	}
}

void Window::initWindow()
{
	window = new sf::RenderWindow(sf::VideoMode(500, 400), "TITLE", sf::Style::Default);
	window->setFramerateLimit(60);
}
