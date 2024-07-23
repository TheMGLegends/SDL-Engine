#include "Collider.h"

#include "CollisionHandler.h"

#include "../GameObject/GameObject.h"

Collider::Collider(std::shared_ptr<GameObject> _owner, Vector2 _position, Vector2 _offset)
	: Component(_owner), position(_position), offset(_offset), colliderType(ColliderType::None)
{
	// INFO: Add the collider to the collision handler
	CollisionHandler::AddCollider(shared_from_this());

	// INFO: Set the collision response functions to the GameObject's collision functions
	collisionEnterResponse = std::bind(&GameObject::OnCollisionEnter, GetOwner(), std::placeholders::_1);
	collisionStayResponse = std::bind(&GameObject::OnCollisionStay, GetOwner(), std::placeholders::_1);
	collisionExitResponse = std::bind(&GameObject::OnCollisionExit, GetOwner(), std::placeholders::_1);

	// INFO: Allow for more than one collider component
	canHaveMultiple = true;
}

void Collider::UpdatePosition()
{
	//position = GetOwner()->GetTransform() + offset;
}

void Collider::RemoveCollidingCollider(std::shared_ptr<Collider> c)
{
	// INFO: Iterates over colliding colliders ensuring the weak_ptr collider exists 
	// before removing the colliding collider that matches the passed in collider
	collidingColliders.erase(
		std::remove_if(
			collidingColliders.begin(), 
			collidingColliders.end(),
			[&c](std::weak_ptr<Collider> collidingCollider) { 
				return !collidingCollider.expired() && collidingCollider.lock() == c; 
			}
		), 
		collidingColliders.end()
	);
}

bool Collider::ContainsCollidingCollider(std::shared_ptr<Collider> c)
{
	// INFO: Iterates over colliding colliders ensuring both colliders exist before
	// checking if the colliding collider matches the passed in collider
	for (auto& collidingCollider : collidingColliders)
	{
		if (!collidingCollider.expired() && collidingCollider.lock() == c)
		{
			return true;
		}
	}
	return false;
}
