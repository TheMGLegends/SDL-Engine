#include "PhysicsHandler.h"

#include "../Generics/Globals.h"

std::vector<std::shared_ptr<Rigidbody>> PhysicsHandler::rigidbodies;
float PhysicsHandler::globalGravityScale = Globals::Physics::DEFAULT_GRAVITY;

void PhysicsHandler::UpdateRigidbodies(float dt)
{
	// FINISH THE LOGIC HERE
}
