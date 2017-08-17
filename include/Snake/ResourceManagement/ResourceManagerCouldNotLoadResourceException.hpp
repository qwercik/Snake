#pragma once

#include <Snake/ResourceManagement/ResourceManagerException.hpp>
#include <string>

namespace Snake
{
	class ResourceManagerCouldNotLoadResourceException : public ResourceManagerException
	{
	public:
		ResourceManagerCouldNotLoadResourceException(const std::string& message) :
		ResourceManagerException(message)
		{
		}
	};
}
