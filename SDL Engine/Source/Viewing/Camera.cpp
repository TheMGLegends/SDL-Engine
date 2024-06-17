#include "Camera.h"

void Camera::Update()
{
	// INFO: If the target is not expired
	if (!target.expired())
	{
		// INFO: Set the camera position to the target's position
		position = target.lock()->position;

		// INFO: Ensure the target remains in the centre of the camera view
		cameraView.x = position.X - cameraView.w / 2.0f;
		cameraView.y = position.Y - cameraView.h / 2.0f;
	}
}
