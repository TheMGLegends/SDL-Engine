#include "Component.h"

int Component::componentCounter = 0;

Component::Component(std::shared_ptr<GameObject> _owner) : owner(_owner), canHaveMultiple(false), componentID(componentCounter++)
{
}
