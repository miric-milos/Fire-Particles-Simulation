#define SDL_MAIN_HANDLED

#include "Screen.h"
#include <iostream>
#include <SDL.h>

using namespace std;
using namespace _custom;

int main(int argv, char* args[])
{
	Screen screen;

	if (!screen.init())
	{
		cout << "Screen failed to initialize" << endl;
		return 1;
	}

	while (true)
	{
		// Update particles
		// Draw particles
		int elapsed = SDL_GetTicks();
		auto blue = (unsigned char)((1 + sin(elapsed * 0.0001)) * 128);
		auto red = (unsigned char)((1 + sin(elapsed * 0.0002)) * 128);
		auto green = (unsigned char)((1 + sin(elapsed * 0.001)) * 128);
		// cout << blue << "  Elapsed: "<< elapsed << endl;
		for (int x = 0; x < Screen::SCREEN_WIDTH; ++x)
		{
			for (int y = 0; y < Screen::SCREEN_HEIGHT; ++y)
			{
				screen.setPixel(y, x, red, green, blue);
			}
		}

		// Draw screen
		screen.update();

		// Check for messages/events
		if (!screen.processEvents())
		{
			// Closing window
			break;
		}
	}


	// Free memory
	screen.close();
	return 0;
}