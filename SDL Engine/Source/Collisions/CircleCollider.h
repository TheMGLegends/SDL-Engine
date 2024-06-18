#pragma once

#include "Collider.h"

/// @brief Holds the data used to represent a circular collider
class CircleCollider : public Collider
{
private:
	float radius;

public:
	//CircleCollider(GameObject* _owner, Vector2 _position, float _radius, Vector2 _offset);
	CircleCollider(std::shared_ptr<GameObject> _owner, Vector2 _position, float _radius, Vector2 _offset = Vector2::ZERO);
	~CircleCollider() override {};

	/// @return The centre point of the circle collider
	inline Vector2 GetCentrePosition() const override { return Vector2(position.X + radius, position.Y + radius); }

	/// @brief Used by the user to update the colliders' values
	void UpdateCircleCollider(float _radius, Vector2 _offset = Vector2::ZERO);

	inline void SetRadius(float _radius) { radius = _radius; }
	inline float GetRadius() const { return radius; }
};

