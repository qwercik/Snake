#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>

#include <Snake/FontManagerCouldNotLoadFontException.hpp>
#include <Snake/FontManagerFontNotLoadedException.hpp>

namespace Snake
{
	class FontManager
	{
	public:
		FontManager();
		
		void loadFont(const std::string& name, const std::string& path);
		void unloadFont(const std::string& name);
		sf::Font& getFont(const std::string& name);
		bool fontExist(const std::string& name);

	private:
		std::unordered_map<std::string, sf::Font> fonts;
	};
}
