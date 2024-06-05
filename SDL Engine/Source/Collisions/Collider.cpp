#include "Collider.h"

#include "CollisionHandler.h"

Collider::Collider(std::shared_ptr<GameObject> _owner, Vector2 _position, Vector2 _offset)
	: Component(_owner), position(_position), offset(_offset), colliderType(ColliderType::None)
{
	// INFO: Add the collider to the collision handler
	CollisionHandler::AddCollider(shared_from_this());
}

void Collider::UpdatePosition()
{
	//position = GetOwner()->GetTransform() + offset;
}
