#pragma once
#include <SDL.h>

namespace _custom
{
	class Screen
	{
	private:
		SDL_Window*    m_window;
		SDL_Renderer*  m_renderer;
		SDL_Texture*   m_texture;
		Uint32*        m_buffer;

	public:
		static const int SCREEN_WIDTH   = 800;
		static const int SCREEN_HEIGHT  = 600;

		Screen();
		bool init();
		bool processEvents();
		void close();
	};
}