#include <Snake/FontManager.hpp>

namespace Snake
{
	FontManager::FontManager()
	{
	}

	void FontManager::loadFont(const std::string& name, const std::string& path)
	{
		if (!fonts[name].loadFromFile(path))
			throw FontManagerCouldNotLoadFontException("Couldn\'t load font file " + path);
	}

	void FontManager::unloadFont(const std::string& name)
	{
		if (!fontExist(name))
			throw FontManagerFontNotLoadedException("Font " + name + " not exist!");

		fonts.erase(fonts.find(name));
	}

	sf::Font& FontManager::getFont(const std::string& name)
	{
		if (!fontExist(name))
			throw FontManagerFontNotLoadedException("Font " + name + " not exist!");

		return fonts[name];
	}

	bool FontManager::fontExist(const std::string& name)
	{
		return fonts.find(name) != fonts.end();	
	}
}
