#include <Snake/Menu.hpp>
#include <string>

namespace Snake
{
	Menu::Menu(ResourceManager<sf::Font>* fontManager, sf::Vector2i windowResoultion)
	{
		this->fontManager = fontManager;

		int windowHeight = windowResoultion.x;
		int windowWidth = windowResoultion.y;

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

		for (int i = 0; i < optionsTexts.size(); ++i)
		{
			sf::Text option;
			option.setFont(fontManager->getResource("data/fonts/dlxfont.ttf"));
			option.setString(optionsTexts[i]);
			option.setCharacterSize(30);
			option.setFillColor(sf::Color::White);
			option.setPosition((400 - option.getGlobalBounds().width) / 2, 100 + 60 * i);

			options.push_back(option);
		}

		options[0].setFillColor(sf::Color::Cyan);
		markedOptionIndex = 0;
	}

	Menu::~Menu()
	{
		fontManager->freeResource("data/fonts/dlxfont.ttf");
	}
	
	void Menu::markPreviousOption()
	{
		options[markedOptionIndex].setFillColor(sf::Color::White);
	
		if (markedOptionIndex == 0)
			markedOptionIndex = options.size() - 1;
		else
			--markedOptionIndex;

		options[markedOptionIndex].setFillColor(sf::Color::Cyan);
	}
	
	void Menu::markNextOption()
	{
		options[markedOptionIndex].setFillColor(sf::Color::White);

		if (markedOptionIndex == options.size() - 1)
			markedOptionIndex = 0;
		else
			++markedOptionIndex;

		options[markedOptionIndex].setFillColor(sf::Color::Cyan);
	}
	
	int Menu::getMarkedOptionIndex()
	{
		return markedOptionIndex;
	}

	void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(titleText);

		for (auto option : options)
			target.draw(option);
	}
}
