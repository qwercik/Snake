#pragma once

#include <Snake/Screen.hpp>
#include <Snake/ResourceManagement/ResourceManager.hpp>
#include <SFML/Graphics.hpp>

namespace Snake
{
	class About : public Screen
	{
	public:
		About(ResourceManager<sf::Font>* fontManager, sf::Vector2u windowResolution);
		virtual void processEvent(const sf::Event& event);

	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		ResourceManager<sf::Font>* fontManager;
		int windowWidth;

		sf::Text titleText;
	};
}
