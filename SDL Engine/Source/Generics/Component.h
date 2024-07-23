#pragma once

#include "Entity.h"

#include <memory>

class GameObject;

/// @brief Abstract base class for all components to inherit from
class Component : public Entity
{
protected:
	//GameObject* owner;
	std::weak_ptr<GameObject> owner;
	bool canHaveMultiple;
	int componentID;

private:
	static int componentCounter;

public:
	//Component(GameObject* _owner);
	Component(std::shared_ptr<GameObject> _owner);
	virtual ~Component() = 0 {};

	inline void SetOwner(std::shared_ptr<GameObject> _owner) { owner = _owner; }
	inline std::shared_ptr<GameObject> GetOwner() { return owner.lock(); }
	
	inline const bool GetCanHaveMultiple() const { return canHaveMultiple; }
	inline const int GetComponentID() const { return componentID; }
};

