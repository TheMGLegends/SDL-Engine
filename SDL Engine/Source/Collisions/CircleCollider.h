#pragma once

#include "Collider.h"

class CircleCollider : public Collider
{
private:
	float radius;

public:
	//CircleCollider(Vector2 _position, float _radius, Vector2 _offset, GameObject* _owner);
	CircleCollider(Vector2 _position, float _radius, Vector2 _offset, std::shared_ptr<GameObject> _owner);
	~CircleCollider() override {}

	void UpdateCircleCollider(float _radius, Vector2 _offset = Vector2::ZERO);

	inline void SetRadius(float _radius) { radius = _radius; }
	inline float GetRadius() const { return radius; }

	inline Vector2 GetCentrePosition() { return Vector2(position.X + radius, position.Y + radius); }
};

