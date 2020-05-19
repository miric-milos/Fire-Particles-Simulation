#define SDL_MAIN_HANDLED

#include "Screen.h"
#include <iostream>
#include <SDL.h>
#include <stdlib.h>
#include <time.h>

#include "Swarm.h"
#include "Particle.h"

using namespace std;
using namespace _custom;

int main(int argv, char* args[])
{
	srand(time(NULL));
	Screen screen;

	if (!screen.init())
	{
		cout << "Screen failed to initialize" << endl;
		return 1;
	}

	Swarm swarm;

	while (true)
	{
		// Update particles
		// Draw particles
		int elapsed = SDL_GetTicks();
		screen.clear();
		swarm.update();

		auto blue = (unsigned char)((1 + sin(elapsed * 0.0001)) * 128);
		auto red = (unsigned char)((1 + sin(elapsed * 0.0002)) * 128);
		auto green = (unsigned char)((1 + sin(elapsed * 0.0003)) * 128);

		const Particle* const particles = swarm.getParticles();
		for (int i = 0; i < Swarm::NPARTICLES; ++i)
		{
			Particle particle = particles[i];
			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2;
			int y = (particle.m_y + 1) * Screen::SCREEN_HEIGHT / 2;

			screen.setPixel(x, y, red, green, blue);
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