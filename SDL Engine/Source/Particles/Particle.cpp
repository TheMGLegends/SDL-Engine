#include "Particle.h"

#include "../Debugging/Debug.h"

Particle::Particle(std::shared_ptr<GameObject> _owner, Texture _texture)
	: Component(_owner), lifetimeDuration(0.0f), currentLifetime(0.0f), 
	  movementSpeed(0.0f), inUse(false), texture(_texture), position(Vector2::ZERO), 
	  lifetimeRange(0.1f, 1.0f), movementSpeedRange(0.1f, 1.0f)
{
}

void Particle::Initialize(Vector2 startingPos)
{
	position = startingPos;
	inUse = true;
	currentLifetime = 0.0f;
}

void Particle::SetLifetimeRange(float min, float max)
{
	if (!ValidRange(min, max))
		return;

	lifetimeRange = Vector2(min, max);
}

void Particle::SetMovementSpeedRange(float min, float max)
{
	if (!ValidRange(min, max))
		return;

	movementSpeedRange = Vector2(min, max);
}

bool Particle::ValidRange(float min, float max)
{
	if (min < 0.0f || max < 0.0f)
	{
		Debug::LogError("Particle::SetMovementSpeedRange(): Min and Max values must be greater than 0.0f");
		return false;
	}

	if (min > max)
	{
		Debug::LogError("Particle::SetMovementSpeedRange(): Min value must be less than the Max value.");
		return false;
	}

	return true;
}
