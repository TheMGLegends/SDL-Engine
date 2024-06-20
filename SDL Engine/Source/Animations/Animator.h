#pragma once

#include "../Generics/Component.h"

#include "../Mathematics/Vector2.h"
#include "../Textures/Texture.h"

#include <SDL.h>

/// @brief Holds the data for the current animation
class Animator : public Component
{
	// INFO: Allows the AnimatorHandler class to access private members of this class
	friend class AnimatorHandler;

private:
	Texture animTexture;

	int animRow;
	int maxRows;

	int animFrame;
	int maxFrames;

	int animSpeed;
	SDL_RendererFlip animFlip;
	int animScale;
	bool isLooping;
	float animElapsedTime;

public:
	//Animator(GameObject* _owner) : Component(_owner) {}
	Animator(std::shared_ptr<GameObject> _owner);
	~Animator() override {};

	void Draw(Vector2 pos, int spriteWidth, int spriteHeight, float scrollingSpeed = 1.0f) const;
	void Draw(int xPos, int yPos, int spriteWidth, int spriteHeight, float scrollingSpeed = 1.0f) const;

	/// @param _isLooping If false the animation will play once and stop on the last frame (Default is true hence the animation will loop)
	void SetAnimation(Texture _animTexture, int _animRow, int _maxRows, int _maxFrames, int _animSpeed, SDL_RendererFlip _animFlip = SDL_FLIP_NONE, int _animScale = 1, bool _isLooping = true);
	const Texture& GetTexture() const { return animTexture; }
};

