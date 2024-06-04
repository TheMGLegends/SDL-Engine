#include "CircleCollider.h"

CircleCollider::CircleCollider(std::shared_ptr<GameObject> _owner, Vector2 _position, float _radius, Vector2 _offset)
	: Collider(_owner, _position, _offset), radius(_radius)
{
	// INFO: Set the collider type to circle
	colliderType = ColliderType::Circle;
}

void CircleCollider::UpdateCircleCollider(float _radius, Vector2 _offset)
{
	radius = _radius;
	offset = _offset;
}
