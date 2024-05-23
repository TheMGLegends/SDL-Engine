#include "Maths.h"

#include <cmath>

const float Maths::PI = 3.1415f;

float Maths::DegToRad(float deg)
{
	return deg * (PI / 180.0f);
}

float Maths::RadToDeg(float rad)
{
	return rad * (180.0f / PI);
}

float Maths::Lerp(float a, float b, float t)
{
	Clamp(t, 0.0f, 1.0f);
	return a + (b - a) * t;
}

float Maths::Clamp(float value, float min, float max)
{
	if (value < min)
		return min;
	else if (value > max)
		return max;
	else
		return value;
}

float Maths::Abs(float value)
{
	return std::abs(value);
}

float Maths::Max(float value1, float value2)
{
	if (value1 > value2)
		return value1;
	else
		return value2; // INFO: If value1 < value2 or value1 == value2, return value2
}

float Maths::Min(float value1, float value2)
{
	if (value1 > value2)
		return value2;
	else
		return value1; // INFO: If value1 < value2 or value1 == value2, return value1
}
