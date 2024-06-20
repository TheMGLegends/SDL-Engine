#pragma once

#include "Texture.h"
#include "../Mathematics/Vector2.h"

#include <SDL.h>

#include <unordered_map>

/// @brief Class that handles texture-related operations
class TextureHandler
{
private:
	static std::unordered_map<Texture, SDL_Texture*> textureLib;
	static int textureCount;

public:
	static void LoadTexture(const char* FILEPATH, Texture& texture, SDL_Renderer* renderer);

#pragma region DrawStaticMethods
	/// @brief Useful for drawing things that do not move in the game world e.g. (UI Elements)
	static void DrawStatic(Texture texture, Vector2 position, int width, int height, 
						   int scale = 1, SDL_RendererFlip flip = SDL_FLIP_NONE);
	
	/// @brief Useful for drawing things that do not move in the game world e.g. (UI Elements)
	static void DrawStatic(Texture texture, int x, int y, int width, int height, 
						   int scale = 1, SDL_RendererFlip flip = SDL_FLIP_NONE);
#pragma endregion

#pragma region DrawDynamicMethods
	/// @brief Useful for drawing things that move in the game world but aren't animated e.g. (Backgrounds, Platforms)
	/// @param scrollingSpeed The speed at which the texture scrolls
	static void DrawDynamic(Texture texture, Vector2 position, int width, int height, float scrollingSpeed = 1.0f, 
							int scale = 1, SDL_RendererFlip flip = SDL_FLIP_NONE);
	
	/// @brief Useful for drawing things that move in the game world but aren't animated e.g. (Backgrounds, Platforms)
	/// @param scrollingSpeed The speed at which the texture scrolls
	static void DrawDynamic(Texture texture, int x, int y, int width, int height, float scrollingSpeed = 1.0f, 
							int scale = 1, SDL_RendererFlip flip = SDL_FLIP_NONE);
#pragma endregion

#pragma region DrawAnimationMethods
	/// @brief Useful for drawing things that move in the game world and are animated e.g. (Player, Enemies)
	/// @param row The row of the sprite sheet
	/// @param frame The frame of the sprite sheet
	static void DrawAnimation(Texture texture, Vector2 position, int width, int height, int row = 0, int frame = 0, 
							  float scrollingSpeed = 1.0f, int scale = 1, SDL_RendererFlip flip = SDL_FLIP_NONE);
	
	/// @brief Useful for drawing things that move in the game world and are animated e.g. (Player, Enemies)
	/// @param row The row of the sprite sheet
	/// @param frame The frame of the sprite sheet
	static void DrawAnimation(Texture texture, int x, int y, int width, int height, int row = 0, int frame = 0, 
							  float scrollingSpeed = 1.0f, int scale = 1, SDL_RendererFlip flip = SDL_FLIP_NONE);
#pragma endregion

	static void Clean();

private:
	static bool TextureExists(Texture texture);

private:
	TextureHandler() = delete;
	~TextureHandler() = delete;
	TextureHandler(const TextureHandler&) = delete;
	TextureHandler& operator=(const TextureHandler&) = delete;
};

