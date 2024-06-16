#include "PhysicsHandler.h"

#include "../Generics/Globals.h"

#include "../Mathematics/Maths.h"

std::vector<std::shared_ptr<Rigidbody>> PhysicsHandler::rigidbodies;
float PhysicsHandler::globalGravityScale = Globals::Physics::DEFAULT_GRAVITY;

void PhysicsHandler::UpdateRigidbodies(float dt)
{
	// INFO: Go through all rigidbodies and update their values
	for (size_t i = 0; i < rigidbodies.size(); i++)
	{
		std::shared_ptr<Rigidbody> rb = rigidbodies[i];

		rb->acceleration.X = rb->force.X / rb->mass;
		rb->acceleration.Y = (rb->force.Y / rb->mass) + (rb->bUseLocalGravity ? rb->localGravityScale : globalGravityScale);

		rb->velocity += rb->acceleration * dt;

		// INFO: Clamp the velocity to the maximum velocity in both directions granted that the maximum velocity is not 0.0f
		if (Globals::Physics::MAX_VELOCITY.X != 0.0f)
			rb->velocity.X = Maths::Clamp(rb->velocity.X, -Globals::Physics::MAX_VELOCITY.X, Globals::Physics::MAX_VELOCITY.X);

		if (Globals::Physics::MAX_VELOCITY.Y != 0.0f)
			rb->velocity.Y = Maths::Clamp(rb->velocity.Y, -Globals::Physics::MAX_VELOCITY.Y, Globals::Physics::MAX_VELOCITY.Y);

		rb->displacement = rb->velocity * dt;
	}
}
