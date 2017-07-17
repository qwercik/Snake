#pragma once

#include <string>
#include <stdexcept>

namespace Snake
{
	class FontManagerCouldNotLoadFontException : public std::runtime_error
	{
	public:
		FontManagerCouldNotLoadFontException(const std::string& message) :
		std::runtime_error(message)
		{
		}
	};
}
