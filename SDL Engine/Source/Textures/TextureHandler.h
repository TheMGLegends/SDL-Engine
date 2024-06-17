#pragma once

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
	static Texture LoadTexture(const char* FILEPATH);

private:
	TextureHandler() = delete;
	~TextureHandler() = delete;
	TextureHandler(const TextureHandler&) = delete;
	TextureHandler& operator=(const TextureHandler&) = delete;
};

