#include "Rigidbody.h"

#include "../Time/TimeHandler.h"

#include "PhysicsHandler.h"

Rigidbody::Rigidbody(std::shared_ptr<GameObject> _owner, float _mass, float _localGravityScale, bool _bUseLocalGravity)
	: Component(_owner), mass(_mass), localGravityScale(_localGravityScale), bUseLocalGravity(_bUseLocalGravity), 
	  force(Vector2::ZERO), acceleration(Vector2::ZERO), velocity(Vector2::ZERO), displacement(Vector2::ZERO)
{
	// INFO: Add the rigidbody to the physics handler
	PhysicsHandler::AddRigidbody(shared_from_this());
}

void Rigidbody::CheckForceMode(const Vector2& FORCE, ForceMode forceMode)
{
	float deltaTime = TimeHandler::GetDeltaTime();

	// INFO: Based on the force mode provided by the user a different force "effect" is achieved
	switch (forceMode)
	{
	case ForceMode::Force:
		force = force * deltaTime / mass;
		break;
	case ForceMode::Acceleration:
		force = force * deltaTime;
		break;
	case ForceMode::Impulse:
		force = force / mass;
		break;
	case ForceMode::VelocityChange:
		force = force;
		break;
	default:
		break;
	}
}
