#pragma once

#include "../Mathematics/Maths.h"

#include <SDL.h>

/// @brief Class used for RGB color representation as well as transparency using an alpha value
class Color
{
public:
	static const Color RED;
	static const Color YELLOW;

	Uint8 R;
	Uint8 G;
	Uint8 B;
	Uint8 A;

public:
	/// @brief Constructor default values give you a fully opaque (255 Alpha) green color (0 Red, 255 Green, 0 Blue)
	Color(Uint8 _R = 0, Uint8 _G = 255, Uint8 _B = 0, Uint8 _A = 255) : R(_R), G(_G), B(_B), A(_A) {}

	/// @param A The alpha value of the random color (Fully opaque by default)
	static inline Color RandomColor(Uint8 A = 255) { return Color(Maths::RandomRange(0, 255), Maths::RandomRange(0, 255), Maths::RandomRange(0, 255), A); }
};

