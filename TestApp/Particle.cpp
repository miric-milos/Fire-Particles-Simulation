#include "Particle.h"
#include <stdlib.h>

Particle::Particle()
{
	// Determines particle position
	 m_x = ((2.0 * rand()) / RAND_MAX) - 1;
	 m_y = ((2.0 * rand()) / RAND_MAX) - 1;
}

void Particle::update()
{
	const double SPEED = 0.01;
	m_x += SPEED;
	m_y += SPEED;
}