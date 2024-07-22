#pragma once

#include "../Generics/Component.h"

#include "../Mathematics/Vector2.h"

#include <functional>
#include <vector>

/// @brief Enum class that represents the different types of colliders
enum class ColliderType
{
	None = 0,

	Box,
	Circle
};

/// @brief Abstract base class for all collider types
class Collider : public Component, public std::enable_shared_from_this<Collider>
{
protected:
	ColliderType colliderType;
	Vector2 position;
	Vector2 offset;
	std::vector<std::weak_ptr<Collider>> collidingColliders;

	/*
	std::function<void(Collider*)> collisionEnterResponse;
	std::function<void(Collider*)> collisionStayResponse;
	std::function<void(Collider*)> collisionExitResponse;
	*/

	std::function<void(std::shared_ptr<Collider>)> collisionEnterResponse;
	std::function<void(std::shared_ptr<Collider>)> collisionStayResponse;
	std::function<void(std::shared_ptr<Collider>)> collisionExitResponse;

public:
	//Collider(GameObject* _owner, Vector2 _position, Vector2 _offset);
	Collider(std::shared_ptr<GameObject> _owner, Vector2 _position, Vector2 _offset);
	virtual ~Collider() = 0 {};

	inline void SetColliderType(ColliderType _colliderType) { colliderType = _colliderType; }
	inline ColliderType GetColliderType() const { return colliderType; }

	void UpdatePosition();
	inline Vector2 GetPosition() const { return position; }

	virtual Vector2 GetCentrePosition() const = 0;

	inline void SetOffset(Vector2 _offset) { offset = _offset; }
	inline Vector2 GetOffset() const { return offset; }

	inline void AddCollidingCollider(std::shared_ptr<Collider> c) { collidingColliders.push_back(std::weak_ptr<Collider>(c)); }
	void RemoveCollidingCollider(std::shared_ptr<Collider> c);
	bool ContainsCollidingCollider(std::shared_ptr<Collider> c);

	inline std::vector<std::weak_ptr<Collider>>& GetCollidingColliders() { return collidingColliders; }

	/*
	inline std::function<void(Collider*)> GetCollisionEnterResponse() const { return collisionEnterResponse; }
	inline std::function<void(Collider*)> GetCollisionStayResponse() const { return collisionStayResponse; }
	inline std::function<void(Collider*)> GetCollisionExitResponse() const { return collisionExitResponse; }
	*/
	inline std::function<void(std::shared_ptr<Collider>)> GetCollisionEnterResponse() const { return collisionEnterResponse; }
	inline std::function<void(std::shared_ptr<Collider>)> GetCollisionStayResponse() const { return collisionStayResponse; }
	inline std::function<void(std::shared_ptr<Collider>)> GetCollisionExitResponse() const { return collisionExitResponse; }
};

