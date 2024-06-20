#include "AnimatorHandler.h"

std::vector<std::shared_ptr<Animator>> AnimatorHandler::animators;

void AnimatorHandler::Update(float dt)
{
	for (auto& animator : animators)
	{
		// INFO: Prevent animation from playing again if it's not set to looping and has reached the last frame
		if (!animator->isLooping && animator->animFrame == animator->maxFrames - 1)
			continue;

		// INFO: Otherwise update the animation
		animator->animElapsedTime += dt;
		animator->animFrame = (static_cast<int>(animator->animElapsedTime) / animator->animSpeed) % animator->maxFrames;
	}
}
