#include "Particle.h"

#include "ParticleHandler.h"

#include "../Debugging/Debug.h"
#include "../Mathematics/Maths.h"
#include "../Textures/TextureHandler.h"

#include <random>

Particle::Particle(std::shared_ptr<GameObject> _owner, Texture _texture)
	: Component(_owner), id(-1), lifetimeDuration(0.0f), currentLifetime(0.0f),
	  movementSpeed(0.0f), inUse(false), isAnimated(false), amount(25), 
	  forceMode(ForceMode::Force), texture(_texture), position(Vector2::ZERO), 
	  travelDirection(Vector2::UP), lifetimeRange(0.1f, 1.0f), movementSpeedRange(0.1f, 1.0f), 
	  travelDirectionRange(Vector2::UP), rb(GetOwner()), animator(GetOwner())
{
	// INFO: Add the particle to the particles handler
	ParticleHandler::AddParticle(shared_from_this());
}

void Particle::Initialize()
{
	// INFO: Randomize the lifetime duration
	currentLifetime = Maths::RandomRange(lifetimeRange.X, lifetimeRange.Y);

	// INFO: Randomize the movement speed
	movementSpeed = Maths::RandomRange(movementSpeedRange.X, movementSpeedRange.Y);

	// INFO: Randomize the travel direction using uniform distribution
	std::mt19937 engine(std::random_device{}());
	std::uniform_real_distribution<float> distribution(travelDirectionRange.X, travelDirectionRange.Y);

	float randomAngleInRadians = distribution(engine);

	// INFO: Calculate travel direction vector
	travelDirection = Vector2(std::cos(randomAngleInRadians), std::sin(randomAngleInRadians));

	// INFO: Apply the force to the particle
	rb.AddForce(travelDirection * movementSpeed, forceMode);
}

void Particle::Update(float dt)
{
	currentLifetime += dt;
	position += rb.GetDisplacement();
	
	if (currentLifetime > lifetimeDuration)
	{
		inUse = false;
		currentLifetime = 0.0f;

		// NEED TO IMPLEMENT A WAY FOR THE PARTICLE TO DISAPPEAR
	}
}

void Particle::Draw(Vector2 pos, int spriteWidth, int spriteHeight, float scrollingSpeed) const
{
	if (isAnimated)
	{
		animator.Draw(pos, spriteWidth, spriteHeight, scrollingSpeed);
	}
	else
	{
		TextureHandler::DrawDynamic(texture, pos, spriteWidth, spriteHeight, scrollingSpeed);
	}
}

void Particle::Draw(int xPos, int yPos, int spriteWidth, int spriteHeight, float scrollingSpeed) const
{
	Draw(Vector2(xPos, yPos), spriteWidth, spriteHeight, scrollingSpeed);
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

void Particle::SetTravelDirectionRange(float fovDegrees, float forwardAngleDegrees)
{
	// INFO: Convert the degrees to radians
	float fovRadians = Maths::DegToRad(fovDegrees);
	float forwardAngleRadians = Maths::DegToRad(forwardAngleDegrees);

	// INFO: Calculate the min and max angles
	float minAngle = forwardAngleRadians - (fovRadians / 2.0f);
	float maxAngle = forwardAngleRadians + (fovRadians / 2.0f);

	// INFO: Set the travel direction range
	travelDirectionRange = Vector2(minAngle, maxAngle);
}

bool Particle::ValidRange(float min, float max)
{
	if (min < 0.0f || max < 0.0f)
	{
		Debug::LogError("Particle::ValidRange: Min and Max values must be greater than 0.0f");
		return false;
	}

	if (min > max)
	{
		Debug::LogError("Particle::ValidRange: Min value must be less than the Max value.");
		return false;
	}

	return true;
}
