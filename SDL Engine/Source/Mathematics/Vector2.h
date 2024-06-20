#pragma once

#include "Maths.h"

#include <sstream>

struct Vector2
{
public:
	float X;
	float Y;

	static const Vector2 UP;
	static const Vector2 DOWN;
	static const Vector2 LEFT;
	static const Vector2 RIGHT;
	static const Vector2 ZERO;
	static const Vector2 ONE;

public:
	Vector2(float _X = 0.0f, float _Y = 0.0f) : X(_X), Y(_Y) {}
	Vector2(int _X = 0, int _Y = 0) : X(static_cast<float>(_X)), Y(static_cast<float>(_Y)) {}

	/// @brief Normalizes the original passed in vector
	static void Normalize(Vector2& v);
	static float Dot(const Vector2& V1, const Vector2& V2);
	static float Distance(const Vector2& V1, const Vector2& V2);
	static Vector2 Lerp(const Vector2& V1, const Vector2& V2, float t);

	float Magnitude() const;
	float SqrMagnitude() const;

	/// @brief Returns a new normalized vector of the vector that called the function
	Vector2 Normalized();

	inline Vector2 operator+(const Vector2& V) const { return Vector2(X + V.X, Y + V.Y); }
	inline Vector2 operator-(const Vector2& V) const { return Vector2(X - V.X, Y - V.Y); }

	inline Vector2 operator*(const Vector2& V) const { return Vector2(X * V.X, Y * V.Y); }
	inline Vector2 operator*(float s) const { return Vector2(X * s, Y * s); }

	inline Vector2 operator/(const Vector2& V) const { return Vector2(X / V.X, Y / V.Y); }
	inline Vector2 operator/(float s) const { return Vector2(X / s, Y / s); }

	Vector2& operator+=(const Vector2& V);
	Vector2& operator-=(const Vector2& V);

	Vector2& operator*=(const Vector2& V);
	Vector2& operator*=(float s);

	Vector2& operator/=(const Vector2& V);
	Vector2& operator/=(float s);

	Vector2& operator=(const Vector2& V);

	inline bool operator==(const Vector2& V) const { return X == V.X && Y == V.Y;}
	inline bool operator!=(const Vector2& V) const { return X != V.X || Y != V.Y; }

	/// @brief User defined conversion to string from Vector2
	inline operator std::string() const { return "(X = " + Maths::FloatToString(X, 1) + ", Y = " + Maths::FloatToString(Y, 1) + ")"; }
	
	/// @brief Ensures things like this: Debug::Log("My Vector: " + ToString(Vect)); work
	friend inline std::ostream& operator<<(std::ostream& os, const Vector2& V) { return os << std::string(V); }
};

