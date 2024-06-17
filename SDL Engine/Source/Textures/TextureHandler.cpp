#include "TextureHandler.h"

#include "SDL_image.h"

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

void TextureHandler::DrawStatic(Texture texture, SDL_Renderer* renderer, Vector2 position, 
								int width, int height, int scale, SDL_RendererFlip flip)
{
	// INFO: Return if the texture is not in the texture library
	if (!TextureExists(texture))
		return;

	SDL_Rect dstRect = { position.X, position.Y, width * scale, height * scale };

	SDL_RenderCopyEx(renderer, textureLib[texture], nullptr, &dstRect, 0, nullptr, flip);
}

void TextureHandler::DrawStatic(Texture texture, SDL_Renderer* renderer, int x, int y, 
								int width, int height, int scale, SDL_RendererFlip flip)
{
	DrawStatic(texture, renderer, Vector2(x, y), width, height, scale, flip);
}

void TextureHandler::DrawDynamic(Texture texture, SDL_Renderer* renderer, /*CAMERA : const Camera&,*/ Vector2 position, 
								 int width, int height, float scrollingSpeed, int scale, SDL_RendererFlip flip)
{
	// INFO: Return if the texture is not in the texture library
	if (!TextureExists(texture))
		return;

	//Vector2 cameraPosition = CAMERA.GetPosition() * scrollingSpeed;
	SDL_Rect dstRect = { position.X /*- cameraPosition.X*/, position.Y /*- cameraPosition.Y*/, width * scale, height * scale};

	SDL_RenderCopyEx(renderer, textureLib[texture], nullptr, &dstRect, 0, nullptr, flip);
}

void TextureHandler::DrawDynamic(Texture texture, SDL_Renderer* renderer, /*CAMERA : const Camera&,*/ int x, int y, 
								 int width, int height, float scrollingSpeed, int scale, SDL_RendererFlip flip)
{
	DrawDynamic(texture, renderer, Vector2(x, y), width, height, scrollingSpeed, scale, flip);
}

void TextureHandler::DrawAnimation(Texture texture, SDL_Renderer* renderer, /*CAMERA : const Camera&,*/ Vector2 position, int width, 
								   int height, int row, int frame, float scrollingSpeed, int scale, SDL_RendererFlip flip)
{
	// INFO: Return if the texture is not in the texture library
	if (!TextureExists(texture))
		return;

	//Vector2 cameraPosition = CAMERA.GetPosition() * scrollingSpeed;
	SDL_Rect srcRect = { frame * width, row * height, width, height };
	SDL_Rect dstRect = { position.X /*- cameraPosition.X*/, position.Y /*- cameraPosition.Y*/, width * scale, height * scale };

	SDL_RenderCopyEx(renderer, textureLib[texture], &srcRect, &dstRect, 0, nullptr, flip);
}

void TextureHandler::DrawAnimation(Texture texture, SDL_Renderer* renderer, /*CAMERA : const Camera&,*/ int x, int y, int width, 
								   int height, int row, int frame, float scrollingSpeed, int scale, SDL_RendererFlip flip)
{
	DrawAnimation(texture, renderer, Vector2(x, y), width, height, row, frame, scrollingSpeed, scale, flip);
}

bool TextureHandler::TextureExists(Texture texture)
{
	if (textureLib.find(texture) == textureLib.end())
	{
		std::cout << "Texture not found in the texture library." << std::endl;
		return false;
	}
	else
	{
		std::cout << "Texture found in the texture library." << std::endl;
		return true;
	}
}
