#pragma once

#include <Snake/GameState.hpp>
#include <Snake/ResourceManagement/ResourceManager.hpp>
#include <Snake/Menu.hpp>
#include <SFML/Graphics.hpp>

namespace Snake
{
	class Game
	{
	public:
		Game();
		~Game();
		
		void run();

	private:
		void handleEvents();
		void renderWindowContent();
		
		const unsigned int WINDOW_WIDTH = 400;
		const unsigned int WINDOW_HEIGHT = 400;

		GameState state;
		ResourceManager<sf::Font> fontManager;
		sf::RenderWindow window;
		
		Menu mainMenu;
	};
}
