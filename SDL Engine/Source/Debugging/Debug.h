#pragma once

#include "../Collisions/BoxCollider.h"
#include "../Collisions/CircleCollider.h"
#include "../Generics/Color.h"

#include <SDL.h>

#include <iostream>

/// @brief Class used for debugging purposes
class Debug
{
public:
	/// @brief Used for drawing the outline of a box collider (Red color by default)
	static void DrawColliderOutline(const BoxCollider& BOX_COLLIDER, SDL_Renderer* renderer, const Color& COLOR = Color::RED);

	/// @brief Used for drawing the outline of a circle collider (Red color by default)
	static void DrawColliderOutline(const CircleCollider& CIRCLE_COLLIDER, SDL_Renderer* renderer, const Color& COLOR = Color::RED);

	static inline void Log(std::string message) { std::cout << message << std::endl; }
	static void LogWarning(std::string message);
	static void LogError(std::string message);
};

