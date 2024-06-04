#include "CircleCollider.h"

CircleCollider::CircleCollider(Vector2 _position, float _radius, Vector2 _offset, std::shared_ptr<GameObject> _owner)
	: Collider(_position, _offset, _owner), radius(_radius)
{
}

void CircleCollider::UpdateCircleCollider(float _radius, Vector2 _offset)
{
	radius = _radius;
	offset = _offset;
}
