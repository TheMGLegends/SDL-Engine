#pragma once

#include <chrono>

/// @brief Class that handles time-related operations
class TimeHandler
{
private:
	static float deltaTime;
	static float elapsedTime;
	static float timeScale;

	static std::chrono::steady_clock::time_point currentTime;
	static std::chrono::steady_clock::time_point previousTime;

public:
	/// @brief Updates the time-related variables
	static void Tick();

	static inline float GetDeltaTime() { return deltaTime; }
	static inline float GetElapsedTime() { return elapsedTime; }
	static inline void SetTimeScale(float _timeScale) { timeScale = _timeScale; }
	static inline float GetTimeScale() { return timeScale; }
};

