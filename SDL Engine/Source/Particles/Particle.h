#pragma once

#include "../Generics/Component.h"

#include "../Animations/Animator.h"
#include "../Mathematics/Vector2.h"
#include "../Physics/Rigidbody.h"
#include "../Textures/Texture.h"

class Particle : public Component, public std::enable_shared_from_this<Particle>
{
	// INFO: Allows the ParticleHandler class to access private members of this class
	friend class ParticleHandler;

private:
	int id;
	float lifetimeDuration;
	float currentLifetime;
	float movementSpeed;

	bool inUse;
	bool isAnimated;

	int amount; // INFO: Number of particles to be initialized
	ForceMode forceMode;

	Texture texture;
	Vector2 position;
	Vector2 travelDirection;
	Vector2 lifetimeRange; // X = Min Value, Y = Max Value
	Vector2 movementSpeedRange; // X = Min Value, Y = Max Value
	Vector2 travelDirectionRange; // X = Min Value (Radians), Y = Max Value (Radians)

public:
	Rigidbody rb;
	Animator animator;

public:
	Particle(std::shared_ptr<GameObject> _owner, Texture _texture);
	~Particle() override {};

	/// @brief Called by the ParticleHandler to initialize the particle
	void Initialize();

	void Update(float dt);
	void Draw(Vector2 pos, int spriteWidth, int spriteHeight, float scrollingSpeed = 1.0f) const;
	void Draw(int xPos, int yPos, int spriteWidth, int spriteHeight, float scrollingSpeed = 1.0f) const;

	void SetLifetimeRange(float min, float max);
	void SetMovementSpeedRange(float min, float max);
	void SetTravelDirectionRange(float fovDegrees, float forwardAngleDegrees);

	inline void SetInUse(bool _inUse) { inUse = _inUse; }
	inline bool GetInUse() const { return inUse; }

	inline void SetIsAnimated(bool _isAnimated) { isAnimated = _isAnimated; }
	inline bool GetIsAnimated() const { return isAnimated; }

	inline void SetAmount(int _amount) { amount = _amount; }
	inline void SetForceMode(ForceMode _forceMode) { forceMode = _forceMode; }

	inline void SetTexture(Texture _texture) { texture = _texture; }
	inline const Texture& GetTexture() const { return texture; }

	bool ValidRange(float min, float max);
};

