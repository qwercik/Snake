#pragma once

#include <Snake/ResourceManagement/ResourceManager.hpp>
#include <Snake/Screen.hpp>
#include <Snake/Menu.hpp>
#include <Snake/About.hpp>
#include <SFML/Graphics.hpp>

namespace Snake
{
	class App 
	{
	public:
		App();
		void run();

	private:
		void handleEvents();
		void renderWindowContent();
		
		ResourceManager<sf::Font> fontManager;
		sf::RenderWindow window;
		
		Screen* currentScreen;
		Menu mainMenu;
		About about;
	};
}
