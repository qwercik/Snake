#include <Snake/Game.hpp>
#include <iostream>

namespace Snake
{
	Game::Game() :
	window(sf::VideoMode(WINDOW_WIDTH, WINDOW_WIDTH), "Snake by Eryk Andrzejewski", sf::Style::Close),
	mainMenu(&fontManager, WINDOW_WIDTH, "SNAKE"),
	{
		state = GameState::Init;
		
		mainMenu.addOption("Start game", [&]() {
			state = GameState::Run;
		});

		mainMenu.addOption("Highscores", [&]() {
			state = GameState::Highscores;
		});
		
		mainMenu.addOption("Settings", [&]() {
			state = GameState::Settings;
		});

		mainMenu.addOption("About", [&]() {
			state = GameState::About;
		});

		mainMenu.addOption("Exit", [&]() {
			state = GameState::Exit;
		});

		window.setFramerateLimit(60);

		state = GameState::MainMenu;
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
			if (event.type == sf::Event::Closed)
				state = GameState::Exit;

			if (state == GameState::MainMenu)
				mainMenu.processEvent(event);
		}
	}

	void Game::renderWindowContent()
	{
		window.clear();
		
		if (state == GameState::MainMenu)
			window.draw(mainMenu);
		
		window.display();
	}
}
