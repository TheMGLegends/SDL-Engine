#include "Transform.h"

#include <cmath>

#include "Maths.h"

Transform::Transform(std::weak_ptr<GameObject> _owner, float X, float Y /*, float zRot*/)
	: Component(_owner), position(X, Y) /*, zRotation(zRot)*/
{
}

Transform::Transform(std::weak_ptr<GameObject> _owner, Vector2 pos /*, float zRot*/)
	: Component(_owner), position(pos) /*, zRotation(zRot)*/
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
