#pragma once

#include "Collider.h"

#include <vector>

#include "BoxCollider.h"
#include "CircleCollider.h"

/// @brief Class that handles collision-related operations
class CollisionHandler
{
private:
	//static std::vector<Collider*> colliders;
	static std::vector<std::shared_ptr<Collider>> colliders;

public:
	/// @brief Identifies collisions between colliders
	static void CheckCollisions();

	//static void Clean();
	//inline static void AddCollider(Collider* collider) { colliders.push_back(collider); }
	//inline static void RemoveCollider(Collider* collider) { colliders.erase(std::remove(colliders.begin(), colliders.end(), collider), colliders.end()); }
	
	inline static void AddCollider(std::shared_ptr<Collider> collider) { colliders.push_back(collider); }
	inline static void RemoveCollider(std::shared_ptr<Collider> collider) { colliders.erase(std::remove(colliders.begin(), colliders.end(), collider), colliders.end()); }

private:
	//static void CircleCircleCollision(CircleCollider* c1, CircleCollider* c2);
	//static void BoxBoxCollision(BoxCollider* b1, BoxCollider* b2);
	//static void CircleBoxCollision(CircleCollider* c, BoxCollider* b);

	static void CircleCircleCollision(std::shared_ptr<CircleCollider> c1, std::shared_ptr<CircleCollider> c2);
	static void BoxBoxCollision(std::shared_ptr<BoxCollider> b1, std::shared_ptr<BoxCollider> b2);
	static void CircleBoxCollision(std::shared_ptr<CircleCollider> c, std::shared_ptr<BoxCollider> b);

private:
	CollisionHandler() = delete;
	~CollisionHandler() = delete;
	CollisionHandler(const CollisionHandler&) = delete;
	CollisionHandler& operator=(const CollisionHandler&) = delete;
};

