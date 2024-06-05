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

void CollisionHandler::Clean()
{
	// INFO: Goes through each collider and access their colliding colliders, removing any that no longer exist
	for (size_t i = 0; i < colliders.size(); i++)
	{
		auto& collidingColliders = colliders[i]->GetCollidingColliders();

		// INFO: Iterators over colliding colliders and removes any that are expired
		collidingColliders.erase(std::remove_if(collidingColliders.begin(), collidingColliders.end(),
			[](std::weak_ptr<Collider> c) { return c.expired(); }), collidingColliders.end());
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

	// INFO: Flag to check if the colliders have collided
	bool hasCollided = false;

	// INFO: Check if the distance between the two circles is less than the sum of their radii
	if ((dx * dx) + (dy * dy) < totalRadius * totalRadius)
	{
		hasCollided = true;
	}

	// INFO: Handle the collision response
	HandleCollisionResponse(c1, c2, hasCollided);
}

void CollisionHandler::BoxBoxCollision(std::shared_ptr<BoxCollider> b1, std::shared_ptr<BoxCollider> b2)
{
	// INFO: Measure to ensure that the colliders are not null
	if (b1 == nullptr || b2 == nullptr)
	{
		std::cout << "CollisionHandler::BoxBoxCollision: One or both colliders are null." << std::endl;
		return;
	}

	// INFO: Get box 1 and 2 positions
	Vector2 b1Pos = b1->GetPosition();
	Vector2 b2Pos = b2->GetPosition();

	// INFO: The min and max x and y values of the first box collider
	float b1MinX = b1Pos.X;
	float b1MaxX = b1Pos.X + b1->GetWidth();

	float b1MinY = b1Pos.Y;
	float b1MaxY = b1Pos.Y + b1->GetHeight();

	// INFO: The min and max x and y values of the second box collider
	float b2MinX = b2Pos.X;
	float b2MaxX = b2Pos.X + b2->GetWidth();

	float b2MinY = b2Pos.Y;
	float b2MaxY = b2Pos.Y + b2->GetHeight();

	// INFO: Flag to check if the colliders have collided
	bool hasCollided = false;

	// INFO: Check for overlap between the two box colliders
	if (b1MaxX > b2MinX && b1MinX < b2MaxX && b1MaxY > b2MinY && b1MinY < b2MaxY)
	{
		hasCollided = true;
	}

	// INFO: Handle the collision response
	HandleCollisionResponse(b1, b2, hasCollided);
}

void CollisionHandler::CircleBoxCollision(std::shared_ptr<CircleCollider> c, std::shared_ptr<BoxCollider> b)
{
	// INFO: Measure to ensure that the colliders are not null
	if (c == nullptr || b == nullptr)
	{
		std::cout << "CollisionHandler::CircleBoxCollision: One or both colliders are null." << std::endl;
		return;
	}

	// INFO: Initialize variables used to determine collision
	float closestX = 0;
	float closestY = 0;

	// INFO: Get the centre position and radius of the circle
	Vector2 cCentrePos = c->GetCentrePosition();
	float cRadius = c->GetRadius();

	// INFO: Get box position
	Vector2 bPos = b->GetPosition();

	// INFO: Get the min and max x and y values of the box collider
	float bMinX = bPos.X;
	float bMaxX = bPos.X + b->GetWidth();

	float bMinY = bPos.Y;
	float bMaxY = bPos.Y + b->GetHeight();

	// INFO: Find the closest x value to the circles' centre x
	if (cCentrePos.X < bMinX)
	{
		closestX = bMinX;
	}
	else if (cCentrePos.X > bMaxX)
	{
		closestX = bMaxX;
	}
	else
	{
		closestX = cCentrePos.X;
	}

	// INFO: Find the closest y value to the circles' centre y
	if (cCentrePos.Y < bMinY)
	{
		closestY = bMinY;
	}
	else if (cCentrePos.Y > bMaxY)
	{
		closestY = bMaxY;
	}
	else
	{
		closestY = cCentrePos.Y;
	}

	// INFO: The difference between the circle's centre and the closest x and y values
	float dx = cCentrePos.X - closestX;
	float dy = cCentrePos.Y - closestY;

	// INFO: Flag to check if the colliders have collided
	bool hasCollided = false;

	// INFO: Check if the distance between the circle and closest x and y values is less than the circle's radius
	if ((dx * dx) + (dy * dy) < cRadius * cRadius)
	{
		hasCollided = true;
	}

	// INFO: Handle the collision response
	HandleCollisionResponse(c, b, hasCollided);
}

void CollisionHandler::HandleCollisionResponse(std::shared_ptr<Collider> c1, std::shared_ptr<Collider> c2, bool hasCollided)
{
}
