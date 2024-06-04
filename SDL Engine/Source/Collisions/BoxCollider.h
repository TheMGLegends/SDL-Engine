#pragma once

#include "Collider.h"

/// @brief Holds the data used to represent a rectangular collider
class BoxCollider : public Collider
{
private:
	float width;
	float height;

public:
	//BoxCollider(GameObject* _owner, Vector2 _position, float _width, float _height, Vector2 _offset);
	BoxCollider(std::shared_ptr<GameObject> _owner, Vector2 _position, float _width, float _height, Vector2 _offset = Vector2::ZERO);
	~BoxCollider() override {}

	/// @brief Used by the user to update the colliders' values
	void UpdateBoxCollider(float _width, float _height, Vector2 _offset = Vector2::ZERO);

	inline void SetWidth(float _width) { width = _width; }
	inline float GetWidth() const { return width; }

	inline void SetHeight(float _height) { height = _height; }
	inline float GetHeight() const { return height; }
};

