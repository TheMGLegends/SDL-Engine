#pragma once

#include "../Mathematics/Vector2.h"

#include <SDL.h>

#include <memory>
#include <unordered_map>

/// @brief Struct that holds the ID of a texture so it can be accessed later
struct Texture
{
	// INFO: Allows the TextureHandler class to access private members of this class
	friend class TextureHandler;

private:
	int id;

public:
	/// @brief Constructor initializes ID to -1 to indicate that it is not a valid texture
	Texture() : id(-1) { }

	inline int GetID() const { return id; }

	/// @brief Comparison operator for Texture struct
	inline bool operator==(const Texture& other) const { return id == other.id; }
};

// Specialize std::hash for Texture
template<>
struct std::hash<Texture> {
	std::size_t operator()(const Texture& texture) const {
		return std::hash<int>()(texture.GetID());
	}
};

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
	static void DrawStatic(Texture texture, SDL_Renderer* renderer, Vector2 position, int width, 
						   int height, int scale = 1, SDL_RendererFlip flip = SDL_FLIP_NONE);
	
	/// @brief Useful for drawing things that do not move in the game world e.g. (UI Elements)
	static void DrawStatic(Texture texture, SDL_Renderer* renderer, int x, int y, int width, 
						   int height, int scale = 1, SDL_RendererFlip flip = SDL_FLIP_NONE);
#pragma endregion

#pragma region DrawDynamicMethods
	/// @brief Useful for drawing things that move in the game world but aren't animated e.g. (Backgrounds, Platforms)
	/// @param scrollingSpeed The speed at which the texture scrolls
	static void DrawDynamic(Texture texture, SDL_Renderer* renderer, /*CAMERA : const Camera&,*/ Vector2 position, int width, 
							int height, float scrollingSpeed = 1.0f, int scale = 1, SDL_RendererFlip flip = SDL_FLIP_NONE);
	
	/// @brief Useful for drawing things that move in the game world but aren't animated e.g. (Backgrounds, Platforms)
	/// @param scrollingSpeed The speed at which the texture scrolls
	static void DrawDynamic(Texture texture, SDL_Renderer* renderer, /*CAMERA : const Camera&,*/ int x, int y, int width, 
							int height, float scrollingSpeed = 1.0f, int scale = 1, SDL_RendererFlip flip = SDL_FLIP_NONE);
#pragma endregion

#pragma region DrawAnimationMethods
	/// @brief Useful for drawing things that move in the game world and are animated e.g. (Player, Enemies)
	/// @param row The row of the sprite sheet
	/// @param frame The frame of the sprite sheet
	static void DrawAnimation(Texture texture, SDL_Renderer* renderer, /*CAMERA : const Camera&,*/ Vector2 position, int width, int height, 
							  int row = 0, int frame = 0, float scrollingSpeed = 1.0f, int scale = 1, SDL_RendererFlip flip = SDL_FLIP_NONE);
	
	/// @brief Useful for drawing things that move in the game world and are animated e.g. (Player, Enemies)
	/// @param row The row of the sprite sheet
	/// @param frame The frame of the sprite sheet
	static void DrawAnimation(Texture texture, SDL_Renderer* renderer, /*CAMERA : const Camera&,*/ int x, int y, int width, int height, 
							  int row = 0, int frame = 0, float scrollingSpeed = 1.0f, int scale = 1, SDL_RendererFlip flip = SDL_FLIP_NONE);
#pragma endregion

private:
	static bool TextureExists(Texture texture);

private:
	TextureHandler() = delete;
	~TextureHandler() = delete;
	TextureHandler(const TextureHandler&) = delete;
	TextureHandler& operator=(const TextureHandler&) = delete;
};

