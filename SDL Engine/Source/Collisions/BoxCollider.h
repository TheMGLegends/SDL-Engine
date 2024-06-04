#pragma once

#include "Collider.h"

class BoxCollider : public Collider
{
private:
	float width;
	float height;

public:
	//BoxCollider(Vector2 _position, float _width, float _height, Vector2 _offset, GameObject* _owner);
	BoxCollider(Vector2 _position, float _width, float _height, Vector2 _offset, std::shared_ptr<GameObject> _owner);
	~BoxCollider() override {}

	void UpdateBoxCollider(float _width, float _height, Vector2 _offset = Vector2::ZERO);

	inline void SetWidth(float _width) { width = _width; }
	inline float GetWidth() const { return width; }

	inline void SetHeight(float _height) { height = _height; }
	inline float GetHeight() const { return height; }
};

