#pragma once

#include "../Generics/Entity.h"

#include "../Collisions/Collider.h"

#include <vector>
#include <memory>

/// @brief Base class for all game objects to inherit from
class GameObject : public Entity, public std::enable_shared_from_this<GameObject>
{
protected:
	//std::vector<Component*> components;
	std::vector<std::shared_ptr<Component>> components;

public:
	GameObject();
	virtual ~GameObject() = 0 {};

	virtual void Start() {}
	virtual void Update(float dt) {}
	virtual void LateUpdate(float dt) {}
	virtual void Draw() {}
	virtual void Reset() {}

	/*
	virtual void OnCollisionEnter(Collider* other) {}
	virtual void OnCollisionStay(Collider* other) {}
	virtual void OnCollisionExit(Collider* other) {}
	*/

	virtual void OnCollisionEnter(std::shared_ptr<Collider> other) {}
	virtual void OnCollisionStay(std::shared_ptr<Collider> other) {}
	virtual void OnCollisionExit(std::shared_ptr<Collider> other) {}

	virtual void OnDestroy() {}

	// INFO: ECS System Methods

	template<class T>
	T* GetComponent();

	template<class T, typename... Args>
	T* AddComponent(Args&&... args);

	/// @param componentID The specific component to be removed, if -1 then the first component found will be removed
	template<class T>
	void RemoveComponent(int componentID = -1);
};

