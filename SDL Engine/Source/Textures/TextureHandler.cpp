#include "TextureHandler.h"

#include "../Viewing/Camera.h"

#include <SDL_image.h>

#include <iostream>

std::unordered_map<Texture, SDL_Texture*> TextureHandler::textureLib;
int TextureHandler::textureCount = 0;

void TextureHandler::LoadTexture(const char* FILEPATH, Texture& texture, SDL_Renderer* renderer)
{
	SDL_Surface* sdlSurface = IMG_Load(FILEPATH);

	if (sdlSurface == nullptr)
	{
		std::cout << "Failed to initialize Surface. SDL error: " << SDL_GetError() << std::endl;
		return;
	}

	SDL_Texture* sdlTexture = SDL_CreateTextureFromSurface(renderer, sdlSurface);

	if (sdlTexture == nullptr)
	{
		std::cout << "Failed to initialize Texture. SDL error: " << SDL_GetError() << std::endl;
		return;
	}

	SDL_FreeSurface(sdlSurface);

	// INFO: Assign the ID of the texture to the current texture count
	texture.id = textureCount;

	textureLib[texture] = sdlTexture;

	// INFO: Increment the texture count ready for the next texture
	textureCount++;
}

void TextureHandler::DrawStatic(Texture texture, Vector2 position, int width, int height, int scale, SDL_RendererFlip flip)
{
	// INFO: Return if the texture is not in the texture library
	if (!TextureExists(texture))
		return;

	SDL_Rect dstRect = { static_cast<int>(position.X), static_cast<int>(position.Y), width * scale, height * scale };

	//SDL_RenderCopyEx(Engine::Instance()->GetCurrentRenderer(), textureLib[texture], nullptr, &dstRect, 0, nullptr, flip);
}

void TextureHandler::DrawStatic(Texture texture, int x, int y, int width, int height, int scale, SDL_RendererFlip flip)
{
	DrawStatic(texture, Vector2(static_cast<float>(x), static_cast<float>(y)), width, height, scale, flip);
}

void TextureHandler::DrawDynamic(Texture texture, Vector2 position, int width, int height, float scrollingSpeed, int scale, SDL_RendererFlip flip)
{
	// INFO: Return if the texture is not in the texture library
	if (!TextureExists(texture))
		return;

	//Vector2 cameraPosition = SceneHandler::Instance()->GetCurrentlyActiveCamera().GetPosition() * scrollingSpeed;
	//SDL_Rect dstRect = { static_cast<int>(position.X - cameraPosition.X), static_cast<int>(position.Y - cameraPosition.Y), width * scale, height * scale };

	//SDL_RenderCopyEx(Engine::Instance()->GetCurrentRenderer(), textureLib[texture], nullptr, &dstRect, 0, nullptr, flip);
}

void TextureHandler::DrawDynamic(Texture texture, int x, int y, int width, int height, float scrollingSpeed, int scale, SDL_RendererFlip flip)
{
	DrawDynamic(texture, Vector2(static_cast<float>(x), static_cast<float>(y)), width, height, scrollingSpeed, scale, flip);
}

void TextureHandler::DrawAnimation(Texture texture, Vector2 position, int width, int height, int row, int frame, float scrollingSpeed, int scale, SDL_RendererFlip flip)
{
	// INFO: Return if the texture is not in the texture library
	if (!TextureExists(texture))
		return;

	//Vector2 cameraPosition = SceneHandler::Instance()->GetCurrentlyActiveCamera().GetPosition() * scrollingSpeed;
	SDL_Rect srcRect = { frame * width, row * height, width, height };
	//SDL_Rect dstRect = { static_cast<int>(position.X - cameraPosition.X), static_cast<int>(position.Y - cameraPosition.Y), width * scale, height * scale };

	//SDL_RenderCopyEx(Engine::Instance()->GetCurrentRenderer(), textureLib[texture], &srcRect, &dstRect, 0, nullptr, flip);
}

void TextureHandler::DrawAnimation(Texture texture, int x, int y, int width, int height, int row, int frame, float scrollingSpeed, int scale, SDL_RendererFlip flip)
{
	DrawAnimation(texture, Vector2(static_cast<float>(x), static_cast<float>(y)), width, height, row, frame, scrollingSpeed, scale, flip);
}

void TextureHandler::Clean()
{
	for (auto& texture : textureLib)
	{
		SDL_DestroyTexture(texture.second);
	}

	textureLib.clear();
	textureCount = 0;

	if (!textureLib.empty())
		std::cout << "Failed to clean the texture library." << std::endl;
}

bool TextureHandler::TextureExists(Texture texture)
{
	if (textureLib.find(texture) == textureLib.end())
	{
		std::cout << "Texture not found in the texture library." << std::endl;
		return false;
	}
	return true;
}
