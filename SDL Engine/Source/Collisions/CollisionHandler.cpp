#include "CollisionHandler.h"

#include <iostream>

//std::vector<Collider*> CollisionHandler::colliders;
std::vector<std::shared_ptr<Collider>> CollisionHandler::colliders;

void CollisionHandler::CheckCollisions()
{
	// INFO: Compares each collider with every other collider in the vector
	for (size_t i = 0; i < colliders.size(); i++)
	{
		for (size_t j = i + 1; j < colliders.size(); j++)
		{
			// INFO: Circle & Circle
			if (colliders[i]->GetColliderType() == ColliderType::Circle && colliders[j]->GetColliderType() == ColliderType::Circle)
			{
				//CircleCircleCollision(dynamic_cast<CircleCollider*>(colliders[i]), dynamic_cast<CircleCollider*>(colliders[j]));
				CircleCircleCollision(std::dynamic_pointer_cast<CircleCollider>(colliders[i]), std::dynamic_pointer_cast<CircleCollider>(colliders[j]));
			}
			// INFO: Box & Box
			else if (colliders[i]->GetColliderType() == ColliderType::Box && colliders[j]->GetColliderType() == ColliderType::Box)
			{
				//BoxBoxCollision(dynamic_cast<BoxCollider*>(colliders[i]), dynamic_cast<BoxCollider*>(colliders[j]));
				BoxBoxCollision(std::dynamic_pointer_cast<BoxCollider>(colliders[i]), std::dynamic_pointer_cast<BoxCollider>(colliders[j]));
			}
			// INFO: Circle & Box
			else if (colliders[i]->GetColliderType() == ColliderType::Circle && colliders[j]->GetColliderType() == ColliderType::Box)
			{
				//CircleBoxCollision(dynamic_cast<CircleCollider*>(colliders[i]), dynamic_cast<BoxCollider*>(colliders[j]));
				CircleBoxCollision(std::dynamic_pointer_cast<CircleCollider>(colliders[i]), std::dynamic_pointer_cast<BoxCollider>(colliders[j]));
			}
			// INFO: Box & Circle
			else if (colliders[i]->GetColliderType() == ColliderType::Box && colliders[j]->GetColliderType() == ColliderType::Circle)
			{
				//CircleBoxCollision(dynamic_cast<CircleCollider*>(colliders[j]), dynamic_cast<BoxCollider*>(colliders[i]));
				CircleBoxCollision(std::dynamic_pointer_cast<CircleCollider>(colliders[j]), std::dynamic_pointer_cast<BoxCollider>(colliders[i]));
			}
		}
	}
}

void CollisionHandler::CircleCircleCollision(std::shared_ptr<CircleCollider> c1, std::shared_ptr<CircleCollider> c2)
{
	// INFO: Measure to ensure that the colliders are not null
	if (c1 == nullptr || c2 == nullptr)
	{
		std::cout << "CollisionHandler::CircleCircleCollision: One or both colliders are null." << std::endl;
		return;
	}	

	// INFO: Circle centre positions
	Vector2 c1CentrePos = c1->GetCentrePosition();
	Vector2 c2CentrePos = c2->GetCentrePosition();

	// INFO: Calculate the difference between the two circles
	float dx = c1CentrePos.X - c2CentrePos.X;
	float dy = c1CentrePos.Y - c2CentrePos.Y;

	// INFO: The sum of the radii of the two circles
	float totalRadius = c1->GetRadius() + c2->GetRadius();

	// INFO: Check if the distance between the two circles is less than the sum of their radii
	// MAKE SURE TO CHECK STATE OF isColliding bool and based on that and the result from this
	// YOU'LL KNOW WHETHER TO DO COLLISION ENTER, STAY OR EXIT
}

void CollisionHandler::BoxBoxCollision(std::shared_ptr<BoxCollider> b1, std::shared_ptr<BoxCollider> b2)
{
	// INFO: Measure to ensure that the colliders are not null
	if (b1 == nullptr || b2 == nullptr)
	{
		std::cout << "CollisionHandler::BoxBoxCollision: One or both colliders are null." << std::endl;
		return;
	}
}

void CollisionHandler::CircleBoxCollision(std::shared_ptr<CircleCollider> c, std::shared_ptr<BoxCollider> b)
{
	// INFO: Measure to ensure that the colliders are not null
	if (c == nullptr || b == nullptr)
	{
		std::cout << "CollisionHandler::CircleBoxCollision: One or both colliders are null." << std::endl;
		return;
	}
}
