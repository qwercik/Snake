#pragma once

#include <Snake/ResourceManagement/ResourceManager.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

namespace Snake
{
	class Menu : public sf::Drawable
	{
	public:
		Menu(ResourceManager<sf::Font>* fontManager);

	private:
		ResourceManager<sf::Font>* fontManager;
		sf::Text titleText;
		std::vector<sf::Text> options;

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	};
}
