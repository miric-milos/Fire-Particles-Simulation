#define SDL_MAIN_HANDLED

#include <iostream>
#include <SDL.h>
using namespace std;

int main(int argv, char* args[])
{
	const int SCREEN_WIDTH   = 800;
	const int SCREEN_HEIGHT  = 600;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL init failed" << endl;
		return 1;
	}

	SDL_Window* window = SDL_CreateWindow("Particle simulation",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		// Window failed to create, exit simulation
		SDL_Quit();
		return 2;
	}
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1,
		SDL_RENDERER_PRESENTVSYNC /* Enables vertical sync */);
	SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ABGR8888,
		SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

	if (renderer == NULL)
	{
		cout << "Could not create renderer" << endl;
		SDL_DestroyWindow(window); // Destroys window
		SDL_Quit();
		return 3;
	}

	if (texture == NULL)
	{
		cout << "Could not create texture" << endl;
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window); // Destroys window
		SDL_Quit();
		return 3;
	}
	
	Uint32* buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT]; // Array the size of the window resolution

	memset(buffer, 50, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

	SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH * sizeof(Uint32));
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);

	bool quit = false;
	SDL_Event event;

	while (!quit)
	{
		// Update particles
		// Draw articles
		// Check for messages/events

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				quit = true;
			}
		}
	}
	

	delete[] buffer;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(texture);
	SDL_DestroyWindow(window); // Destroys window
	SDL_Quit();

	return 0;
}