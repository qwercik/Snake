#pragma once

#include <SFML/Graphics.hpp>
#include <Snake/TexturesManager.hpp>

namespace Snake
{
	class Game
	{
	public:
		enum class Status
		{
			Init,
			Run,
			Pause,
			Exit
		};

		Game();
		~Game();
		
		void run();
		
		Status getStatus() const;
	private:
		void handleEvents();
		void renderWindowContent();

		sf::RenderWindow window;
		TexturesManager texturesManager;
		Status status;
	};
}
