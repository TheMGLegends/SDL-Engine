#pragma once

#include <SDL_mixer.h>

#include <unordered_map>

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

/// @brief Class that handles audio-related operations
class AudioHandler
{
private:
	static std::unordered_map<Audio, Mix_Music*> musicLib;
	static std::unordered_map<Audio, Mix_Chunk*> sfxLib;
	static int audioCount;

public:
	static void LoadMusic(const char* FILEPATH, Audio& audio);
	static void LoadSFX(const char* FILEPATH, Audio& audio);

	/// @param loops The number of loops to play the music for. -1 plays the music indefinitely, 0 plays the music once and stops
	static void PlayMusic(Audio music, int loops = 0);

	/// @param loops The number of loops to play the sfx for. -1 plays the sfx indefinitely, 0 plays the sfx once and stops
	static void PlaySFX(Audio sfx, int loops = 0);

	static inline void SetMusicVolume(int volume) { Mix_VolumeMusic(volume); }
	static void SetSFXVolume(Audio sfx, int volume);

	static void Clean();

private:
	/// @param isMusic If false the function will check the SFX library, if true the function will check the Music library
	static bool AudioExists(Audio audio, bool isMusic = false);
};

