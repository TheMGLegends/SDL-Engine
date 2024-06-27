#include "ParticleHandler.h"

#include "../Debugging/Debug.h"

std::vector<std::shared_ptr<Particle>> ParticleHandler::particles;
int ParticleHandler::particleID = 0;

void ParticleHandler::Update(float dt)
{
	for (auto& particle : particles)
	{
		if (particle->inUse)
		{
			particle->Update(dt);
		}
	}
}

void ParticleHandler::PlayParticleEffect(std::shared_ptr<Particle> particle, int amount, Vector2 startingPos)
{
	int remainingParticles = amount;

	for (size_t i = 0; i < particles.size(); i++)
	{
		if (remainingParticles == 0)
			break;

		// INFO: If the IDs match (i.e. The same particle type)
		if (particle->id == particles[i]->id && !particles[i]->inUse)
		{
			remainingParticles--;

			// INFO: Set the particle to be in use
			particles[i]->inUse = true;

			// INFO: Set the starting position of the particle
			particles[i]->position = startingPos;
		}
	}

	// INFO: Debug Warning if there are still remaining particles
	if (remainingParticles > 0)
	{
		Debug::LogWarning("ParticleHandler::PlayParticleEffect: Not enough available particles, remaining particle amount: " + std::to_string(remainingParticles));
	}
}

void ParticleHandler::InitializeParticle(std::shared_ptr<Particle> parentParticle)
{
	// INFO: Includes the parent particle hence -1
	int particlesToSpawn = parentParticle->amount - 1;

	// INFO: Set the ID of the parent particle
	parentParticle->id = particleID;

	for (size_t i = 0; i < particlesToSpawn; i++)
	{
		// INFO: Creates a new particle with the same values as the parent particle
		std::shared_ptr<Particle> particle = std::make_shared<Particle>(*parentParticle);

		// INFO: Initialize the new particle to randomize necessary values
		particle->Initialize();

		// INFO: Add the new particle to the list
		particles.push_back(particle);
	}

	// INFO: Increment ID for the next particle
	particleID++;
}
