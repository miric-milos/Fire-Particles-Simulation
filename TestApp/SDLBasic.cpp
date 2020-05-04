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
	
	SDL_DestroyWindow(window); // Destroys window
	SDL_Quit();

	return 0;
}