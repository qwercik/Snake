#pragma once

#include <SFML/Graphics.hpp>

namespace Snake
{
	class Screen : public sf::Drawable
	{
	public:
		virtual void processEvent(const sf::Event& event) = 0;

	protected:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
	};
}
