#include "Vector2.h"

#include <cmath>

#include "Maths.h"

const Vector2 Vector2::UP(0, 1);
const Vector2 Vector2::DOWN(0, -1);
const Vector2 Vector2::LEFT(-1, 0);
const Vector2 Vector2::RIGHT(1, 0);
const Vector2 Vector2::ZERO(0, 0);
const Vector2 Vector2::ONE(1, 1);

void Vector2::Normalize(Vector2& v)
{
	float mag = v.Magnitude();

	// INFO: Prevent Division by Zero
	if (mag != 0)
		v /= mag;
}

float Vector2::Dot(const Vector2& V1, const Vector2& V2)
{
	return (V1.X * V2.X) + (V1.Y * V2.Y);
}

float Vector2::Distance(const Vector2& V1, const Vector2& V2)
{
	Vector2 V = V1 - V2;
	return V.Magnitude();
}

Vector2 Vector2::Lerp(const Vector2& V1, const Vector2& V2, float t)
{
	t = Maths::Clamp(t , 0.0f, 1.0f);
	return V1 + (V2 - V1) * t;
}

float Vector2::Magnitude()
{
	return std::sqrt(std::powf(X, 2) + std::powf(Y, 2));
}

float Vector2::SqrMagnitude()
{
	return std::powf(X, 2) + std::powf(Y, 2);
}

Vector2 Vector2::Normalized()
{
	Vector2 v = *this;
	Normalize(v);
	return v;
}

Vector2& Vector2::operator+=(const Vector2& V)
{
	X += V.X;
	Y += V.Y;
	return *this;
}

Vector2& Vector2::operator-=(const Vector2& V)
{
	X -= V.X;
	Y -= V.Y;
	return *this;
}

Vector2& Vector2::operator*=(const Vector2& V)
{
	X *= V.X;
	Y *= V.Y;
	return *this;
}

Vector2& Vector2::operator*=(float s)
{
	X *= s;
	Y *= s;
	return *this;
}

Vector2& Vector2::operator/=(const Vector2& V)
{
	X /= V.X;
	Y /= V.Y;
	return *this;
}

Vector2& Vector2::operator/=(float s)
{
	X /= s;
	Y /= s;
	return *this;
}

Vector2& Vector2::operator=(const Vector2& V)
{
	// INFO: Self-Assignment Safe
	if (this != &V)
	{
		X = V.X;
		Y = V.Y;
	}
	
	return *this;
}
