#include "GameObjectHandler.h"

std::vector<std::shared_ptr<GameObject>> GameObjectHandler::gameObjects;

void GameObjectHandler::Start()
{
	// INFO: Execute the Start method for all game objects
	for (auto& gameObject : gameObjects)
		gameObject->Start();
}

void GameObjectHandler::Update(float dt)
{
	// INFO: First Execute the Update method for all game objects
	for (auto& gameObject : gameObjects)
		gameObject->Update(dt);

	// INFO: Then Execute the LateUpdate method for all game objects
	for (auto& gameObject : gameObjects)
		gameObject->LateUpdate(dt);
}

void GameObjectHandler::Draw()
{
	// INFO: Execute the Draw method for all game objects
	for (auto& gameObject : gameObjects)
		gameObject->Draw();
}

void GameObjectHandler::Reset()
{
	// INFO: Execute the Reset method for all game objects
	for (auto& gameObject : gameObjects)
		gameObject->Reset();
}

void GameObjectHandler::RemoveGameObject(std::shared_ptr<GameObject> gameObject)
{
	gameObjects.erase(std::remove(gameObjects.begin(), gameObjects.end(), gameObject), gameObjects.end());

	// INFO: Since GO is no longer in the gameObjects vector, it will be destroyed
	gameObject->OnDestroy();
}
