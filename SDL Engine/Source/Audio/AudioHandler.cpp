#include "AudioHandler.h"

#include "../Debugging/Debug.h"

std::unordered_map<Audio, Mix_Music*> AudioHandler::musicLib;
std::unordered_map<Audio, Mix_Chunk*> AudioHandler::sfxLib;
int AudioHandler::audioCount = 0;

void AudioHandler::LoadMusic(const char* FILEPATH, Audio& audio)
{
	Mix_Music* music = Mix_LoadMUS(FILEPATH);

	if (music == nullptr)
	{
		Debug::LogWarning("AudioHandler::LoadMusic: Failed to initialize music with path: " + std::string(FILEPATH) + ". SDL_Mix error : " + std::string(Mix_GetError()));
	}

	// INFO: Assign the ID of the audio clip to the current audio count
	audio.id = audioCount;

	musicLib[audio] = music;

	// INFO: Increment the audio count ready for the next audio clip
	audioCount++;
}

void AudioHandler::LoadSFX(const char* FILEPATH, Audio& audio)
{
	Mix_Chunk* sfx = Mix_LoadWAV(FILEPATH);

	if (sfx == nullptr)
	{
		Debug::LogWarning("AudioHandler::LoadSFX: Failed to initialize sfx with path: " + std::string(FILEPATH) + ". SDL_Mix error : " + std::string(Mix_GetError()));
	}

	// INFO: Assign the ID of the audio clip to the current audio count
	audio.id = audioCount;

	sfxLib[audio] = sfx;

	// INFO: Increment the audio count ready for the next audio clip
	audioCount++;
}

void AudioHandler::PlayMusic(Audio music, int loops)
{
	// INFO: Return if the audio clip is not in the music library
	if (!AudioExists(music, true))
		return;

	// INFO: Plays the Music
	if (Mix_PlayMusic(musicLib[music], loops) == -1)
		Debug::LogWarning("AudioHandler::PlayMusic: Failed to play music. SDL_Mix error: " + std::string(Mix_GetError()));
}

void AudioHandler::PlaySFX(Audio sfx, int loops)
{
	// INFO: Return if the audio clip is not in the sfx library
	if (!AudioExists(sfx, false))
		return;

	// INFO: Plays the SFX
	if (Mix_PlayChannel(-1, sfxLib[sfx], loops) == -1)
		Debug::LogWarning("AudioHandler::PlaySFX: Failed to play sfx. SDL_Mix error: " + std::string(Mix_GetError()));
}

void AudioHandler::SetSFXVolume(Audio sfx, int volume)
{
	// INFO: Return if the audio clip is not in the sfx library
	if (!AudioExists(sfx, false))
		return;

	Mix_VolumeChunk(sfxLib[sfx], volume);
}

void AudioHandler::Clean()
{
	for (auto& music : musicLib)
	{
		Mix_FreeMusic(music.second);
	}

	for (auto& sfx : sfxLib)
	{
		Mix_FreeChunk(sfx.second);
	}

	musicLib.clear();
	sfxLib.clear();
	audioCount = 0;

	if (!musicLib.empty())
		Debug::LogWarning("AudioHandler::Clean: Failed to clean the music library.");

	if (!sfxLib.empty())
		Debug::LogWarning("AudioHandler::Clean: Failed to clean the sfx library.");
}

bool AudioHandler::AudioExists(Audio audio, bool isMusic)
{
	if (isMusic)
	{
		if (musicLib.find(audio) == musicLib.end())
		{
			Debug::LogWarning("AudioHandler::AudioExists: Audio clip not found in the music library.");
			return false;
		}
	}
	else
	{
		if (sfxLib.find(audio) == sfxLib.end())
		{
			Debug::LogWarning("AudioHandler::AudioExists: Audio clip not found in the sfx library.");
			return false;
		}
	}
	return true;
}
