#include "Collider.h"

Collider::Collider(Vector2 _position, Vector2 _offset, std::shared_ptr<GameObject> _owner)
	: Component(_owner), position(_position), offset(_offset), isColliding(false), colliderType(ColliderType::None)
{
}

void Collider::UpdatePosition()
{
	//position = GetOwner()->GetTransform() + offset;
}
