#pragma once

#include "../Generics/Component.h"

#include "../Mathematics/Vector2.h"
#include "../Generics/Globals.h"

class PhysicsHandler;

/// @brief Enum class that represents the different types of forces that can be applied to a rigidbody
enum class ForceMode
{
	None = 0,

	Force,
	Acceleration,
	Impulse,
	VelocityChange
};

/// @brief Holds the data used to represent a rigidbody
class Rigidbody : public Component, public std::enable_shared_from_this<Rigidbody>
{
	// INFO: Allows the PhysicsHandler class to access private members of this class
	friend class PhysicsHandler;

private:
	float mass;
	float localGravityScale;
	bool bUseLocalGravity;
	Vector2 force;
	Vector2 acceleration;
	Vector2 velocity;
	Vector2 displacement;

public:
	//Rigidbody(GameObject* _owner, float _mass = 1.0f, float _localGravityScale = Globals::Physics::DEFAULT_GRAVITY, bool _bUseLocalGravity = false);
	Rigidbody(std::shared_ptr<GameObject> _owner, float _mass = 1.0f, float _localGravityScale = Globals::Physics::DEFAULT_GRAVITY, bool _bUseLocalGravity = false);
	~Rigidbody() override {}

	inline void SetMass(float _mass) { mass = _mass; }
	inline float GetMass() const { return mass; }

	inline void SetLocalGravityScale(float _localGravityScale) { localGravityScale = _localGravityScale; }
	inline float GetLocalGravityScale() const { return localGravityScale; }

	inline void SetUseLocalGravity(bool _bUseLocalGravity) { bUseLocalGravity = _bUseLocalGravity; }
	inline bool GetUseLocalGravity() const { return bUseLocalGravity; }

	inline void AddForce(const Vector2& FORCE, ForceMode forceMode = ForceMode::Force) { CheckForceMode(FORCE, forceMode); }
	inline void AddForce(float x, float y, ForceMode forceMode = ForceMode::Force) { CheckForceMode(Vector2(x, y), forceMode); }
	inline void AddForceX(float x, ForceMode forceMode = ForceMode::Force) { CheckForceMode(Vector2(x, 0.0f), forceMode); }
	inline void AddForceY(float y, ForceMode forceMode = ForceMode::Force) { CheckForceMode(Vector2(0.0f, y), forceMode); }

	inline void CancelForce() { force = Vector2::ZERO; }
	inline void CancelForceX() { force.X = Vector2::ZERO.X; }
	inline void CancelForceY() { force.Y = Vector2::ZERO.Y; }

	inline Vector2 GetAcceleration() const { return acceleration; }
	inline Vector2 GetVelocity() const { return velocity; }
	inline Vector2 GetDisplacement() const { return displacement; }

private:
	void CheckForceMode(const Vector2& FORCE, ForceMode forceMode);
};

