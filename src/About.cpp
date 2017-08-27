#include <Snake/About.hpp>

namespace Snake
{
	
	About::About(ResourceManager<sf::Font>* fontManager, sf::Vector2u windowResolution)
	{
		this->fontManager = fontManager;
		windowWidth = windowResolution.x;

		titleText.setFont(fontManager->getResource("data/fonts/dlxfont.ttf"));
		titleText.setCharacterSize(50);
		titleText.setFillColor(sf::Color::White);
		titleText.setString("About");
		titleText.setPosition((windowWidth - titleText.getGlobalBounds().width) / 2, 20);
	}

	void About::processEvent(const sf::Event& event)
	{
		
	}

	void About::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(titleText);
	}
}
