#include <Snake/Game.hpp>
#include <stdexcept>
#include <iostream>

namespace Snake
{
	Game::Game()
	{
		state = GameState::Init;

		window.create(
			sf::VideoMode(400, 400),
			"Snake by Eryk Andrzejewski",
			sf::Style::Close
		);	
	}
	
	Game::~Game()
	{
		if (window.isOpen())
			window.close();
	}

	void Game::run()
	{
		while (state != GameState::Exit)
		{
			handleEvents();
			renderWindowContent();
		}
	}
	
	void Game::handleEvents()
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed:
					state = GameState::Exit;
					break;
			}
		}
	}

	void Game::renderWindowContent()
	{
		window.clear();
		window.display();
	}
}
