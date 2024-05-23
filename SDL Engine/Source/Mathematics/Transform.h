#pragma once

#include "../Generics/Component.h"

#include "Vector2.h"

class Transform : public Component
{
public:
	Vector2 position;
	//float zRotation;

public:
	//Transform(GameObject* _owner, float X, float Y, float zRot);
	Transform(std::weak_ptr<GameObject> _owner, float X, float Y /*, float zRot*/);
	//Transform(GameObject* _owner, Vector2 pos, float zRot);
	Transform(std::weak_ptr<GameObject> _owner, Vector2 pos /*, float zRot*/);
	~Transform() override {}

	inline void Translate(float X, float Y) { position.X += X; position.Y += Y; }
	inline void Translate(const Vector2& translation) { position += translation; }

	inline void TranslateX(float X) { position.X += X; }
	inline void TranslateY(float Y) { position.Y += Y; }

	/*
	inline void RotateZ(float angle) { zRotation += angle; }

	Vector2 Up() const;
	Vector2 Right() const;
	*/
};

