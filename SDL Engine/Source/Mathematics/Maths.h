#pragma once

struct Maths
{
public:
	static const float PI;

public:
	static float DegToRad(float deg);
	static float RadToDeg(float rad);
	static float Lerp(float a, float b, float t);
	static float Clamp(float value, float min, float max);
	static float Abs(float value);
	static float Max(float value1, float value2);
	static float Min(float value1, float value2);
};

