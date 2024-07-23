#include "GameObject.h"

GameObject::GameObject()
{
	// INFO: All game objects will have a transform component
	//AddComponent(new Transform());
}

template<class T>
inline T* GameObject::GetComponent()
{
	for (auto& component : components)
	{
		T* castedComponent = dynamic_cast<T*>(component.get());

		if (castedComponent != nullptr)
			return castedComponent;
	}

	// INFO: If the component is not found, return nullptr
	return nullptr;
}

template<class T, typename ...Args>
T* GameObject::AddComponent(Args && ...args)
{
	static_assert(std::is_base_of<Component, T>::value, "T must derive from Component");

	// INFO: Check if the component already exists
	T* existingComponent = GetComponent<T>();

	// INFO: If there can't be more than one component of the same type then return the existing component
	if (existingComponent != nullptr && !static_cast<Component*>(existingComponent)->GetCanHaveMultiple())
		return existingComponent;

	// INFO: Create a new component
	components.push_back(std::make_shared<T>(std::forward<Args>(args)...));

	// INFO: Return the newly created component
	return dynamic_cast<T*>(components.back().get());
}

template<class T>
void GameObject::RemoveComponent(int componentID)
{
	bool checkID = componentID != -1;

	for (auto it = components.begin(); it != components.end(); ++it)
	{
		T* castedComponent = dynamic_cast<T*>(it->get());

		if (castedComponent != nullptr)
		{
			if (checkID && it->get()->GetComponentID() != componentID)
				continue;

			components.erase(it);
			return;
		}
	}
}
