#pragma once

#include "Particle.h"

class Swarm
{
private:
	Particle* m_Particles;
public:
	const static int NPARTICLES = 5000;

	Swarm();
	~Swarm();
	const Particle* const getParticles();
	void update();
};

