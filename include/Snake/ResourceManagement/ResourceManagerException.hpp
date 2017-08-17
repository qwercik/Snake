#pragma once

#include <string>
#include <stdexcept>

namespace Snake
{
	class ResourceManagerException : public std::runtime_error
	{
	public:
		ResourceManagerException(const std::string& message) :
		std::runtime_error(message)
		{
		}
	};
}
