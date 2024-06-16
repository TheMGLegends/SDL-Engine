#pragma once

#include <SDL.h>

#include "../Mathematics/Vector2.h"

/// @brief Class that is used to store information about the user's mouse
class Mouse
{
	// INFO: Allows the InputHandler class to access private members of this class
	friend class InputHandler;

private:
	static SDL_Rect mouseInfo;

public:
	static inline void SetMouseInfo(int x, int y, int width, int height) { mouseInfo = { x, y, width, height }; }
	static inline void SetMouseInfO(Vector2 pos, int width, int height) { mouseInfo = { static_cast<int>(pos.X), static_cast<int>(pos.Y), width, height }; }
	static inline SDL_Rect GetMouseInfo() { return mouseInfo; }
};

