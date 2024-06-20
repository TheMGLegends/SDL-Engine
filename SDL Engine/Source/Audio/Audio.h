#pragma once

#include <memory>

/// @brief Struct that holds the ID of an audio clip so it can be accessed later
struct Audio
{
	// INFO: Allows the AudioHandler class to access private members of this class
	friend class AudioHandler;

private:
	int id;

public:
	/// @brief Constructor initializes ID to -1 to indicate that it is not a valid audio clip
	Audio() : id(-1) { }

	inline int GetID() const { return id; }

	/// @brief Comparison operator for Texture struct
	inline bool operator==(const Audio& other) const { return id == other.id; }
};

/// @brief Specialize std::hash for Audio
template<>
struct std::hash<Audio> {
	std::size_t operator()(const Audio& audio) const {
		return std::hash<int>()(audio.GetID());
	}
};