#define SDL_MAIN_HANDLED

#include "Screen.h"
#include <iostream>
#include <SDL.h>

using namespace std;

int main(int argv, char* args[])
{
	_custom::Screen screen;

	if (!screen.init())
	{
		cout << "Screen failed to initialize" << endl;
		return 1;
	}

	while (true)
	{
		// Update particles
		// Draw articles
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