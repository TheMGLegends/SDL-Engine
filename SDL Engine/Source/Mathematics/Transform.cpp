#include "Transform.h"

#include <cmath>

#include "Maths.h"

Transform::Transform(std::shared_ptr<GameObject> _owner, float X, float Y /*, float _zRotation*/)
	: Component(_owner), position(X, Y) /*, zRotation(_zRotation)*/
{
}

Transform::Transform(std::shared_ptr<GameObject> _owner, Vector2 _position /*, float _zRotation*/)
	: Component(_owner), position(_position) /*, zRotation(_zRotation)*/
{
}

/*
Vector2 Transform::Up() const
{
	float radians = Maths::DegToRad(zRotation);
	return Vector2(-std::sin(radians), std::cos(radians));
}

Vector2 Transform::Right() const
{
	float radians = Maths::DegToRad(zRotation);
	return Vector2(std::cos(radians), std::sin(radians));
}
*/
