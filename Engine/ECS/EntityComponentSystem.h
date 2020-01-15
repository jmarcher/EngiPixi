#ifndef ENTITYCOMPONENTSYSTEM_H
#define ENTITYCOMPONENTSYSTEM_H

#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <memory>
#include <vector>

class Component;
class Entity;

using ComponentID = std::size_t;

inline ComponentID getComponentTypeID()
{
    static ComponentID lastID = 0;

    return lastID++;
}

template <typename T> inline ComponentID getComponentTypeID() noexcept
{
    static ComponentID typeId = getComponentTypeID();

    return typeId;
}

constexpr std::size_t maxComponents = 32;

using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*, maxComponents>;

class Component
{
public:
    Entity* entity;

    virtual void init()
    {
    }
    virtual void update()
    {
    }
    virtual void draw()
    {
    }

    virtual ~Component()
    {
    }
};

class Entity
{
public:
    void update()
    {
        for(auto& c : this->components) {
            c->update();
        }
    }

    void draw()
    {
        for(auto& c : this->components) {
            c->draw();
        }
    }

    bool isActive() const
    {
        return this->active;
    }

    void destroy()
    {
        this->active = false;
    }

    template <typename T> bool hasComponents() const
    {
        return componentBitSet[getComponentTypeID<T>()];
    }

    template <typename T, typename... TArgs> T& addComponent(TArgs&&... mArgs)
    {
        T* c(new T(std::forward<TArgs>(mArgs)...));
        c->entity = this;
        std::unique_ptr<Component> uniquePointer { c };

        components.emplace_back(std::move(uniquePointer));

        componentArray[getComponentTypeID<T>()] = c;
        componentBitSet[getComponentTypeID<T>()] = true;

        c->init();

        return *c;
    }

    template <typename T> T& getComponent() const
    {
        auto ptr(componentArray[getComponentTypeID<T>()]);

        return *static_cast<T*>(ptr);
    }

protected:
    bool active = true;
    std::vector<std::unique_ptr<Component>> components;

    ComponentArray componentArray;
    ComponentBitSet componentBitSet;
};

class Manager
{
public:
    Manager(){}
    ~Manager(){}

    void update()
    {
        for(auto& e : entites) {
            e->update();
        }
    }

    void draw()
    {
        for(auto& e : entites) {
            e->draw();
        }
    }

    void refresh()
    {
        entites.erase(std::remove_if(std::begin(entites), std::end(entites),
                          [](const std::unique_ptr<Entity>& mEntity) { return !mEntity->isActive(); }),
            std::end(entites));
    }

    Entity& addEntity()
    {
        Entity* e = new Entity();
        std::unique_ptr<Entity> uPtr { e };
        entites.emplace_back(std::move(uPtr));

        return *e;
    }

protected:
    std::vector<std::unique_ptr<Entity>> entites;
};

#endif // ENTITYCOMPONENTSYSTEM_H
