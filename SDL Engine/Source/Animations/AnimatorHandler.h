#pragma once

#include "Animator.h"

#include <vector>

class AnimatorHandler
{
private:
	//static std::vector<Animator*> animators;
	static std::vector<std::shared_ptr<Animator>> animators;

public:
	static void Update(float dt);

	//static inline void AddAnimator(Animator* animator) { animators.push_back(animator); }
	//static inline void RemoveAnimator(Animator* animator) { animators.erase(std::remove(animators.begin(), animators.end(), animator), animators.end()); }

	static inline void AddAnimator(std::shared_ptr<Animator> animator) { animators.push_back(animator); }
	static inline void RemoveAnimator(std::shared_ptr<Animator> animator) { animators.erase(std::remove(animators.begin(), animators.end(), animator), animators.end()); }

private:
	AnimatorHandler() = delete;
	~AnimatorHandler() = delete;
	AnimatorHandler(const AnimatorHandler&) = delete;
	AnimatorHandler& operator=(const AnimatorHandler&) = delete;
};

