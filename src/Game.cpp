#include <Snake/Game.hpp>

namespace Snake
{
	Game::Game()
	{
		window.create(
			sf::VideoMode(400, 400),
			"Snake by Eryk Andrzejewski",
			sf::Style::Close
		);

		status = Status::Init; 
	};
	
	Game::~Game()
	{
		if (window.isOpen())
			window.close();
	}

	void Game::run()
	{
		status = Status::Run;

		while (status != Status::Exit)
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
					status = Status::Exit;
					break;
			}
		}
	}

	void Game::renderWindowContent()
	{
		window.clear();
		window.display();
	}

	Game::Status Game::getStatus() const
	{
		return status;
	};
}
