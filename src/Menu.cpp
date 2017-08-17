#include <Snake/Menu.hpp>
#include <string>

namespace Snake
{
	Menu::Menu(ResourceManager<sf::Font>* fontManager)
	{
		this->fontManager = fontManager;
	
		titleText.setFont(fontManager->getResource("data/fonts/dlxfont.ttf"));
		titleText.setString("SNAKE");
		titleText.setCharacterSize(50);
		titleText.setFillColor(sf::Color::White);
		titleText.setPosition((400 - titleText.getGlobalBounds().width) / 2, 20);

		std::vector<std::string> optionsTexts = {
			"Play",
			"Highscores",
			"Settings",
			"About",
			"Exit"
		};
	}

	void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(titleText);	
	}
}
