#pragma once

#include "GameObject.h"

#include <vector>

class GameObjectHandler
{
private:
	//static std::vector<GameObject*> gameObjects;
	static std::vector<std::shared_ptr<GameObject>> gameObjects;

public:
	static void Start();
	static void Update(float dt);
	static void Draw();
	static void Reset();

	//static void AddGameObject(GameObject* gameObject) { gameObjects.push_back(gameObject); }
	//static void RemoveGameObject(GameObject* gameObject) { gameObjects.erase(std::remove(gameObjects.begin(), gameObjects.end(), gameObject), gameObjects.end()); }

	static void AddGameObject(std::shared_ptr<GameObject> gameObject) { gameObjects.push_back(gameObject); }
	static void RemoveGameObject(std::shared_ptr<GameObject> gameObject);

private:
	GameObjectHandler() = delete;
	~GameObjectHandler() = delete;
	GameObjectHandler(const GameObjectHandler&) = delete;
	GameObjectHandler& operator=(const GameObjectHandler&) = delete;
};

