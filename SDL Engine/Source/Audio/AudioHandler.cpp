#include "AudioHandler.h"

#include <iostream>

std::unordered_map<Audio, Mix_Music*> AudioHandler::musicLib;
std::unordered_map<Audio, Mix_Chunk*> AudioHandler::sfxLib;
int AudioHandler::audioCount = 0;

void AudioHandler::LoadMusic(const char* FILEPATH, Audio& audio)
{
	Mix_Music* music = Mix_LoadMUS(FILEPATH);

	if (music == nullptr)
	{
		std::cout << "Failed to initialise music. SDL_Mix error: " << Mix_GetError() << std::endl;
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
		std::cout << "Failed to initialise sfx. SDL_Mix error: " << Mix_GetError() << std::endl;
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
		std::cout << "Failed to play music. SDL_Mix error: " << Mix_GetError() << std::endl;
}

void AudioHandler::PlaySFX(Audio sfx, int loops)
{
	// INFO: Return if the audio clip is not in the sfx library
	if (!AudioExists(sfx, false))
		return;

	// INFO: Plays the SFX
	if (Mix_PlayChannel(-1, sfxLib[sfx], loops) == -1)
		std::cout << "SFX could not be played. SDL_Mixer error: " << Mix_GetError() << std::endl;
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
		std::cout << "Failed to clean the music library." << std::endl;

	if (!sfxLib.empty())
		std::cout << "Failed to clean the sfx library." << std::endl;
}

bool AudioHandler::AudioExists(Audio audio, bool isMusic)
{
	if (isMusic)
	{
		if (musicLib.find(audio) == musicLib.end())
		{
			std::cout << "Audio clip not found in the music library." << std::endl;
			return false;
		}
	}
	else
	{
		if (sfxLib.find(audio) == sfxLib.end())
		{
			std::cout << "Audio clip not found in the sfx library." << std::endl;
			return false;
		}
	}
	return true;
}
