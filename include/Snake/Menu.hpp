#pragma once

#include <Snake/ResourceManagement/ResourceManager.hpp>
#include <Snake/Screen.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <functional>

namespace Snake
{
	class Menu : public Screen 
	{
	public:
		Menu(ResourceManager<sf::Font>* fontManager, sf::Vector2u windowResolution, const std::string& title);
		~Menu();
		
		void setTitle(const std::string& title);
		void addOption(const std::string& optionText, std::function<void()> function);
		virtual void processEvent(const sf::Event& event);

	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		void markPreviousOption();
		void markNextOption();

		ResourceManager<sf::Font>* fontManager;
		unsigned int windowWidth;
	
		sf::Text titleText;
		std::vector<std::pair<sf::Text, std::function<void()>>> options;
		unsigned int markedOptionIndex;
	};
}
