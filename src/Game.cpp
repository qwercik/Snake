#include <Snake/Game.hpp>

namespace Snake
{
	Game::Game() :
	mainMenu(&fontManager, sf::Vector2i(WINDOW_WIDTH, WINDOW_WIDTH))
	{
		state = GameState::Init;

		window.create(
			sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
			"Snake by Eryk Andrzejewski",
			sf::Style::Close
		);

		window.setFramerateLimit(60);
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

				case sf::Event::KeyPressed:
					if (event.key.code == sf::Keyboard::Up)
						mainMenu.markPreviousOption();
					else if (event.key.code == sf::Keyboard::Down)
						mainMenu.markNextOption();

					break;
			}
		}
	}

	void Game::renderWindowContent()
	{
		window.clear();
		window.draw(mainMenu);
		window.display();
	}
}
