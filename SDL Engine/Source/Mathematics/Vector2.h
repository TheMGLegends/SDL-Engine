#pragma once

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

	static void Normalize(Vector2& v);
	static float Dot(const Vector2& V1, const Vector2& V2);
	static float Distance(const Vector2& V1, const Vector2& V2);
	static Vector2 Lerp(const Vector2& V1, const Vector2& V2, float t);

	float Magnitude();
	float SqrMagnitude();
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
};

