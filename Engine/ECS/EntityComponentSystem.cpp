#include "EntityComponentSystem.h"

void Entity::addGroup(Group mGroup)
{
    this->groupBitset[mGroup] = true;
    this->manager.addToGroup(this, mGroup);
}
