#pragma once

namespace Globals
{
	namespace Physics
	{
		const float DEFAULT_GRAVITY = 9.81f;

		// INFO: Granted that the maximum velocity is 0.0f, the velocity will not be clamped
		const Vector2 MAX_VELOCITY = Vector2(0.0f, 0.0f);
	}
}