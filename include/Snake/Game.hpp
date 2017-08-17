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

		GameState state;
		ResourceManager<sf::Font> fontManager;
		
		Menu mainMenu;

		sf::RenderWindow window;
	};
}
