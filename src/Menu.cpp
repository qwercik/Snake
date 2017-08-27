#include <Snake/Menu.hpp>
#include <string>

namespace Snake
{
	Menu::Menu(ResourceManager<sf::Font>* fontManager, sf::Vector2u windowResolution, const std::string& title)
	{
		this->fontManager = fontManager;
		windowWidth = windowResolution.x;	

		titleText.setFont(fontManager->getResource("data/fonts/dlxfont.ttf"));
		titleText.setCharacterSize(50);
		titleText.setFillColor(sf::Color::White);
		setTitle(title);
	}

	Menu::~Menu()
	{
		fontManager->freeResource("data/fonts/dlxfont.ttf");
	}
	
	void Menu::setTitle(const std::string& title)
	{
		titleText.setString(title);
		titleText.setPosition((windowWidth - titleText.getGlobalBounds().width) / 2, 20);
	}

	void Menu::addOption(const std::string& optionName, std::function<void()> function)
	{
		sf::Text option;
		option.setFillColor(sf::Color::White);
		option.setFont(fontManager->getResource("data/fonts/dlxfont.ttf"));
		option.setCharacterSize(30);
		option.setString(optionName);
		option.setPosition((windowWidth - option.getGlobalBounds().width) / 2, 100 + 60 * options.size());
		
		if (options.size() == 0)
		{
			markedOptionIndex = 0;
			option.setFillColor(sf::Color::Cyan);
		}

		options.push_back(std::pair<sf::Text, std::function<void()>>(option, function));
	}
	
	void Menu::processEvent(const sf::Event& event)
	{
		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
				case sf::Keyboard::Up:
					markPreviousOption();
					break;

				case sf::Keyboard::Down:
					markNextOption();
					break;

				case sf::Keyboard::Return:
					options[markedOptionIndex].second();
					break;
			}
		}
	}
	
	void Menu::markPreviousOption()
	{
		options[markedOptionIndex].first.setFillColor(sf::Color::White);
	
		if (markedOptionIndex == 0)
			markedOptionIndex = options.size() - 1;
		else
			--markedOptionIndex;

		options[markedOptionIndex].first.setFillColor(sf::Color::Cyan);
	}
	
	void Menu::markNextOption()
	{
		options[markedOptionIndex].first.setFillColor(sf::Color::White);

		if (markedOptionIndex == options.size() - 1)
			markedOptionIndex = 0;
		else
			++markedOptionIndex;

		options[markedOptionIndex].first.setFillColor(sf::Color::Cyan);
	}
	
	void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(titleText);

		for (auto option : options)
			target.draw(option.first);
	}
}
