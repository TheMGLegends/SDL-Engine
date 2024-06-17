#pragma once

#include "../Mathematics/Transform.h"
#include "../Mathematics/Vector2.h"

#include <SDL.h>

#include <memory>

/// @brief Camera class that handles the view of the game world and how things move in it
class Camera
{
private:
	Vector2 position;
	//Transform* target;
	std::weak_ptr<Transform> target;
	SDL_Rect cameraView;

public:
	void Update();

	inline Vector2 GetPosition() const { return position; }

	//inline void SetTarget(Transform* target) { this->target = target; }
	//inline Transform* GetTarget() const { return target; }
	inline void SetTarget(std::weak_ptr<Transform> target) { this->target = target; }
	inline std::weak_ptr<Transform> GetTarget() const { return target; }

	inline SDL_Rect GetCameraView() const { return cameraView; }
};

