#pragma once

#include "../Generics/Component.h"

#include "../Mathematics/Vector2.h"
#include "../Textures/Texture.h"

class Particle : public Component
{
private:
	float lifetimeDuration;
	float currentLifetime;
	float movementSpeed;

	bool inUse;

	Texture texture;
	Vector2 position;
	Vector2 lifetimeRange; // X = Min, Y = Max
	Vector2 movementSpeedRange; // X = Min, Y = Max

public:
	Particle(std::shared_ptr<GameObject> _owner, Texture _texture);
	~Particle() override {};

	/// @brief Called by the ParticleHandler to initialize the particle
	void Initialize(Vector2 startingPos);
	inline void Initialize(float startingXPos, float startingYPos) { Initialize(Vector2(startingXPos, startingYPos)); }

	// NEED IMPLEMENTING <--------------------------------------
	void Update(float dt);
	void Draw();

	void SetLifetimeRange(float min, float max);
	void SetMovementSpeedRange(float min, float max);

	inline void SetInUse(bool _inUse) { inUse = _inUse; }
	inline bool GetInUse() const { return inUse; }

	inline void SetTexture(Texture _texture) { texture = _texture; }
	inline const Texture& GetTexture() const { return texture; }

	bool ValidRange(float min, float max);
};

