#pragma once

#include <string>
#include <stdexcept>

namespace Snake
{
	class FontManagerFontNotLoadedException : public std::runtime_error
	{
	public:
		FontManagerFontNotLoadedException(const std::string& message) :
		std::runtime_error(message)
		{
		}
	};
}
