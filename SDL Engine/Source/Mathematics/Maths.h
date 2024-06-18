#pragma once

#include <string>

/// @brief Static holder struct for mathematical operations
struct Maths
{
public:
	static const float PI;

public:
	static float DegToRad(float deg);
	static float RadToDeg(float rad);
	static float Lerp(float a, float b, float t);
	static float Clamp(float value, float min, float max);
	static int Clamp(int value, int min, int max);
	static float Abs(float value);
	static float Max(float value1, float value2);
	static float Min(float value1, float value2);
	static int RandomRange(int min, int max);
	static std::string FloatToString(float value, int precision = 2);
};

