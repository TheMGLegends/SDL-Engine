#include "BoxCollider.h"

BoxCollider::BoxCollider(Vector2 _position, float _width, float _height, Vector2 _offset, std::shared_ptr<GameObject> _owner)
	: Collider(_position, _offset, _owner), width(_width), height(_height)
{
}

void BoxCollider::UpdateBoxCollider(float _width, float _height, Vector2 _offset)
{
	width = _width;
	height = _height;
	offset = _offset;
}
