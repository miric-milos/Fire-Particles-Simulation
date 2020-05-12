#include "Swarm.h"

Swarm::Swarm()
{
	m_Particles = new Particle[NPARTICLES];
}

Swarm::~Swarm()
{
	delete[] m_Particles;
}

const Particle* const Swarm::getParticles()
{
	return m_Particles;
}