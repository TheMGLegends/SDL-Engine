#include "BoxCollider.h"

BoxCollider::BoxCollider(std::shared_ptr<GameObject> _owner, Vector2 _position, float _width, float _height, Vector2 _offset)
	: Collider(_owner, _position, _offset), width(_width), height(_height)
{
	// INFO: Set the collider type to box
	colliderType = ColliderType::Box;
}

void BoxCollider::UpdateBoxCollider(float _width, float _height, Vector2 _offset)
{
	width = _width;
	height = _height;
	offset = _offset;
}
