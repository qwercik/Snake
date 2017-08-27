#include <Snake/App.hpp>
#include <iostream>

namespace Snake
{
	App::App() :
	window(
		sf::VideoMode(400, 400),
		"Snake by Eryk Andrzejewski",
		sf::Style::Close
	),
	mainMenu(
		&fontManager,
		window.getSize(),
		"SNAKE"
	),
	about(
		&fontManager,
		window.getSize()
	)
	{
		mainMenu.addOption("Start game", [&]() {
		});

		mainMenu.addOption("Highscores", [&]() {
		});
		
		mainMenu.addOption("Settings", [&]() {
		});

		mainMenu.addOption("About", [&]() {
			currentScreen = &about;
		});

		mainMenu.addOption("Exit", [&]() {
			window.close();
		});

		window.setFramerateLimit(60);

		currentScreen = &mainMenu;
	}

	void App::run()
	{
		while (window.isOpen())
		{
			handleEvents();
			renderWindowContent();
		}
	}
	
	void App::handleEvents()
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			currentScreen->processEvent(event);
		}
	}

	void App::renderWindowContent()
	{
		window.clear();
		window.draw(*currentScreen);	
		window.display();
	}
}
