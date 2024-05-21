#pragma once

/// @brief Abstract class used as a base for all entities
class Entity
{
protected:
	bool isActive;

public:
	Entity() : isActive(true) {}
	virtual ~Entity() = 0;

	inline void SetIsActive(bool _isActive) { isActive = _isActive; }
	inline bool GetIsActive() const { return isActive; }
};

