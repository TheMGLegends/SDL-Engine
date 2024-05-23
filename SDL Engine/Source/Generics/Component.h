#pragma once

#include "Entity.h"

#include <memory>

#include "../GameObject/GameObject.h"

class Component : public Entity
{
protected:
	//GameObject* owner;
	std::weak_ptr<GameObject> owner;

public:
	//Component(GameObject* _owner) : owner(_owner) {}
	Component(std::weak_ptr<GameObject> _owner) : owner(_owner) {}
	virtual ~Component() = 0 {}
};

