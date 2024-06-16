#pragma once

#include "Rigidbody.h"

#include <vector>

/// @brief Class that handles physics-related operations
class PhysicsHandler
{
private:
	//static std::vector<Rigidbody*> rigidbodies;
	static std::vector<std::shared_ptr<Rigidbody>> rigidbodies;
	static float globalGravityScale;

public:
	/// @brief Updates the values of all rigidbodies
	static void UpdateRigidbodies(float dt);

	//static void AddRigidbody(Rigidbody* rigidbody);
	//static void RemoveRigidbody(Rigidbody* rigidbody);
	static inline void AddRigidbody(std::shared_ptr<Rigidbody> rigidbody) { rigidbodies.push_back(rigidbody); }
	static inline void RemoveRigidbody(std::shared_ptr<Rigidbody> rigidbody) { rigidbodies.erase(std::remove(rigidbodies.begin(), rigidbodies.end(), rigidbody), rigidbodies.end()static ); }

	static inline void SetGlobalGravityScale(float _globalGravityScale) { globalGravityScale = _globalGravityScale; }
	static inline float GetGlobalGravityScale() { return globalGravityScale; }

private:
	PhysicsHandler() = delete;
	~PhysicsHandler() = delete;
	PhysicsHandler(const PhysicsHandler&) = delete;
	PhysicsHandler& operator=(const PhysicsHandler&) = delete;
};

