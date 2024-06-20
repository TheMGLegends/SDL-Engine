#include "Animator.h"

#include "AnimatorHandler.h"
#include "../Textures/TextureHandler.h"

Animator::Animator(std::shared_ptr<GameObject> _owner) 
	: Component(_owner), animTexture(), animRow(0), maxRows(0), 
	animFrame(0), maxFrames(0), animSpeed(0), animFlip(SDL_FLIP_NONE), 
	animScale(0), isLooping(true), animElapsedTime(0.0f)
{
}

void Animator::Draw(Vector2 pos, int spriteWidth, int spriteHeight, float scrollingSpeed) const
{
	TextureHandler::DrawAnimation(animTexture, pos, spriteWidth, spriteHeight, animRow, animFrame, scrollingSpeed, animScale, animFlip);
}

void Animator::Draw(int xPos, int yPos, int spriteWidth, int spriteHeight, float scrollingSpeed) const
{
	Draw(Vector2(xPos, yPos), spriteWidth, spriteHeight, scrollingSpeed);
}

void Animator::SetAnimation(Texture _animTexture, int _animRow, int _maxRows, int _maxFrames, int _animSpeed, SDL_RendererFlip _animFlip, int _animScale, bool _isLooping)
{
	animTexture = _animTexture;
	animRow = _animRow;
	maxRows = _maxRows;
	animFrame = 0;
	maxFrames = _maxFrames;
	animSpeed = _animSpeed;
	animFlip = _animFlip;
	animScale = _animScale;
	isLooping = _isLooping;

	// INFO: Resets the elapsed time of the animation ready for the new animation
	animElapsedTime = 0.0f;
}
