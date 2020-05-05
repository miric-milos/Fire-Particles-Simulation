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
		for (int x = 0; x < Screen::SCREEN_HEIGHT; ++x)
		{
			for (int y = 0; y < Screen::SCREEN_WIDTH; ++y)
			{
				screen.setPixel(x, y, 255, 0, 0);
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