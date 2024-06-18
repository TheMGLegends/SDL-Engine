#include "Debug.h"

#include <cmath>

void Debug::DrawColliderOutline(const BoxCollider& BOX_COLLIDER, SDL_Renderer* renderer, const Color& COLOR)
{
	SDL_Rect boxCollider{ static_cast<int>(BOX_COLLIDER.GetPosition().X), static_cast<int>(BOX_COLLIDER.GetPosition().Y), static_cast<int>(BOX_COLLIDER.GetWidth()), static_cast<int>(BOX_COLLIDER.GetHeight()) };

	// INFO: Save the previous color so you can restore it after drawing the collider
	Color previousColor;
	SDL_GetRenderDrawColor(renderer, &previousColor.R, &previousColor.G, &previousColor.B, &previousColor.A);

	SDL_SetRenderDrawColor(renderer, COLOR.R, COLOR.G, COLOR.B, COLOR.A);
	SDL_RenderDrawRect(renderer, &boxCollider);

	// INFO: Restore the previous render draw color
	SDL_SetRenderDrawColor(renderer, previousColor.R, previousColor.G, previousColor.B, previousColor.A);
}

void Debug::DrawColliderOutline(const CircleCollider& CIRCLE_COLLIDER, SDL_Renderer* renderer, const Color& COLOR)
{
	// INFO: Save the previous color so you can restore it after drawing the collider
	Color previousColor;
	SDL_GetRenderDrawColor(renderer, &previousColor.R, &previousColor.G, &previousColor.B, &previousColor.A);

	// INFO: Set the renderer draw color to the color that is going to represent the circle
	SDL_SetRenderDrawColor(renderer, COLOR.R, COLOR.G, COLOR.B, COLOR.A);

	// INFO: Circle Info
	int radius = static_cast<int>(CIRCLE_COLLIDER.GetRadius());
	int diameter = radius * 2;
	Vector2 centrePos = CIRCLE_COLLIDER.GetCentrePosition();

	// INFO: Scans the rect sized area of the circle and detects whether the current
	// point is within the bounds of the circle, if so it will be drawn otherwise
	// it will be ignored
	for (int width = 0; width < diameter; width++)
	{
		for (int height = 0; height < diameter; height++)
		{
			int dx = radius - width; // INFO: Starts far right going all the way left
			int dy = radius - height; // INFO: Starts bottom going all the way up

			Vector2 displacedVector{ (float)dx, (float)dy };

			// INFO: Given that the displaced vector is on the circumference of the circle a point will be drawn
			if (std::ceil(displacedVector.Magnitude()) == radius)
				SDL_RenderDrawPoint(renderer, static_cast<int>(centrePos.X + dx), static_cast<int>(centrePos.Y + dy));
		}
	}

	// INFO: Restore the previous render draw color
	SDL_SetRenderDrawColor(renderer, previousColor.R, previousColor.G, previousColor.B, previousColor.A);
}

void Debug::LogWarning(std::string message)
{
	// INFO: Set color to bold yellow
	std::cout << "\033[1;33;1m";

	std::cout << "Warning: " + message << std::endl;

	// INFO: Reset color to default
	std::cout << "\033[0m";
}

void Debug::LogError(std::string message)
{
	// INFO: Set color to bold red
	std::cout << "\033[1;31;1m";

	std::cout << "Error: " + message << std::endl;

	// INFO: Reset color to default
	std::cout << "\033[0m";
}
