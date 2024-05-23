#pragma once

#include "Entity.h"

#include <memory>

#include "../GameObject/GameObject.h"

/// @brief Abstract base class for all components to inherit from
class Component : public Entity
{
protected:
	//GameObject* owner;
	std::weak_ptr<GameObject> owner;

public:
	//Component(GameObject* _owner) : owner(_owner) {}
	
	/// @brief Constructor
	/// @param _owner : The GameObject that owns this component
	Component(std::weak_ptr<GameObject> _owner) : owner(_owner) {}
	virtual ~Component() = 0 {}
};

