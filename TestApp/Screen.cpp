#include "Screen.h"
#include <iostream>
#include <SDL.h>

namespace _custom
{
	Screen::Screen() 
		: m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL)
	{
		// All fields set to NULL
	}

	bool Screen::init()
	{
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			return false;
		}

		m_window = SDL_CreateWindow("Particle simulation",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if (m_window == NULL)
		{
			// Window failed to create, exit simulation
			SDL_Quit();
			return false;
		}
		m_renderer = SDL_CreateRenderer(m_window, -1,
			SDL_RENDERER_PRESENTVSYNC /* Enables vertical sync */);
		m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

		if (m_renderer == NULL)
		{
			SDL_DestroyWindow(m_window);
			SDL_Quit();
			return false;
		}

		if (m_texture == NULL)
		{
			SDL_DestroyRenderer(m_renderer);
			SDL_DestroyWindow(m_window); 
			SDL_Quit();
			return false;
		}

		Uint32* buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT]; // Array the size of the window resolution

		// Fills the buffer with pixel data
		memset(buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

		for (size_t i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++)
		{
			*(buffer + i) = 0x0000FFFF;
		}

		SDL_UpdateTexture(m_texture, NULL, buffer, SCREEN_WIDTH * sizeof(Uint32));
		SDL_RenderClear(m_renderer);
		SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
		SDL_RenderPresent(m_renderer);

		// Everything succeeded
		return true;
	}

	bool Screen::processEvents()
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				return false;
			}
		}

		return true;
	}

	void Screen::close()
	{
		// Releases recources
		delete[] m_buffer;
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyTexture(m_texture);
		SDL_DestroyWindow(m_window); // Destroys window
		SDL_Quit();
	}
}