#pragma once

#include "../Generics/Component.h"

#include "Vector2.h"

/// @brief Transform component class for GameObjects
class Transform : public Component
{
public:
	Vector2 position;
	//float zRotation;

public:
	//Transform(GameObject* _owner, float X, float Y, float zRot);
	//Transform(GameObject* _owner, Vector2 pos, float zRot);
	
	/// @brief Constructor
	/// @param _owner : The GameObject that owns this component
	Transform(std::shared_ptr<GameObject> _owner, float X, float Y /*, float _zRotation*/);

	/// @brief Constructor
	/// @param _owner : The GameObject that owns this component
	Transform(std::shared_ptr<GameObject> _owner, Vector2 _position /*, float _zRotation*/);

	~Transform() override {};

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

