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

	sf::Vector2f renderingSize(window->getSize());

	sf::RenderTexture players, enemies, bullets;
	sf::ContextSettings settings;
	players.create(renderingSize.x, renderingSize.y, settings);
	enemies.create(renderingSize.x, renderingSize.y, settings);
	bullets.create(renderingSize.x, renderingSize.y, settings);
	
	game.renderPlayer(renderingSize, players);
	players.display();
	window->draw(sf::Sprite(players.getTexture()));

	game.renderEnemies(renderingSize, enemies);
	enemies.display();
	window->draw(sf::Sprite(enemies.getTexture()));
	
	game.renderBullets(renderingSize, bullets);
	bullets.display();
	window->draw(sf::Sprite(bullets.getTexture()));


	window->display();
}

void Window::update()
{
	game.update();
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
