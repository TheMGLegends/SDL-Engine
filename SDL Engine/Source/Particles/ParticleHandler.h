#pragma once

#include "Particle.h"

#include <vector>

class ParticleHandler
{
private:
	//static std::vector<Particle*> particles;
	static std::vector<std::shared_ptr<Particle>> particles;
	static int particleID;

public:
	static void Update(float dt);

	//static void AddParticle(Particle* particle);
	//static void PlayParticleEffect(Particle* particle, int amount, Vector2 startingPos);
	static inline void AddParticle(std::shared_ptr<Particle> particle) { particles.push_back(particle); InitializeParticle(particle); }
	static void PlayParticleEffect(std::shared_ptr<Particle> particle, int amount, Vector2 startingPos);


private:
	static void InitializeParticle(std::shared_ptr<Particle> parentParticle);

private:
	ParticleHandler() = delete;
	~ParticleHandler() = delete;
	ParticleHandler(const ParticleHandler&) = delete;
	ParticleHandler& operator=(const ParticleHandler&) = delete;
};

