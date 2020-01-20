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

class Manager;

using ComponentID = std::size_t;
using Group = std::size_t;

inline ComponentID getNewComponentTypeID() {
    static ComponentID lastID = 0u;

    return lastID++;
}

template<typename T>
inline ComponentID getComponentTypeID() noexcept {
    static ComponentID typeId = getNewComponentTypeID();

    return typeId;
}

constexpr std::size_t maxComponents = 32;
constexpr std::size_t maxGroups = 32;

using ComponentBitSet = std::bitset<maxComponents>;
using GroupBitset = std::bitset<maxGroups>;
using ComponentArray = std::array<Component *, maxComponents>;

class Component {
public:
    Entity *entity;

    virtual void init() {
    }

    virtual void update() {
    }

    virtual void draw() {
    }

    virtual ~Component() {
    }
};

class Entity {

protected:
    Manager &manager;

    std::vector<std::unique_ptr<Component>> components;

    ComponentArray componentArray;
    ComponentBitSet componentBitSet;
    GroupBitset groupBitset;

    bool active = true;

public:
    Entity(Manager &mManager)
            : manager(mManager) {
    }

    void update() {
        for (auto &c : this->components) {
            c->update();
        }
    }

    void draw() {
        for (auto &c : this->components) {
            c->draw();
        }
    }

    bool isActive() const {
        return this->active;
    }

    void destroy() {
        this->active = false;
    }

    bool hasGroup(Group group) {
        return groupBitset[group];
    }

    void addGroup(Group group);

    void delGroup(Group group) {
        this->groupBitset[group] = false;
    }

    template<typename T>
    bool hasComponents() const {
        return componentBitSet[getComponentTypeID<T>()];
    }

    template<typename T, typename... TArgs>
    T &addComponent(TArgs &&... mArgs) {
        T *c(new T(std::forward<TArgs>(mArgs)...));
        c->entity = this;
        std::unique_ptr<Component> uniquePointer{c};

        components.emplace_back(std::move(uniquePointer));

        componentArray[getComponentTypeID<T>()] = c;
        componentBitSet[getComponentTypeID<T>()] = true;

        c->init();

        return *c;
    }

    template<typename T>
    T &getComponent() const {
        auto ptr(componentArray[getComponentTypeID<T>()]);

        return *static_cast<T *>(ptr);
    }
};

class Manager {

protected:
    std::vector<std::unique_ptr<Entity>> entities;
    std::array<std::vector<Entity *>, maxGroups> groupedEntities;

public:
    Manager() {
    }

    ~Manager() {
    }

    void update() {
        for (auto &e : entities) {
            e->update();
        }
    }

    void draw() {
        for (auto &e : entities) {
            e->draw();
        }
    }

    void refresh() {


        for (auto i(0u); i < maxGroups; i++) {
            auto &v(groupedEntities[i]);
            v.erase(
                    std::remove_if(std::begin(v), std::end(v),
                                   [i](Entity *mEntity) {
                                       return !mEntity->isActive() || !mEntity->hasGroup(i);
                                   }),
                    std::end(v));
        }


        entities.erase(std::remove_if(std::begin(entities), std::end(entities),
                                      [](const std::unique_ptr<Entity> &mEntity) { return !mEntity->isActive(); }),
                       std::end(entities));
    }

    void addToGroup(Entity *entity, Group group) {
        groupedEntities[group].emplace_back(entity);
    }

    std::vector<Entity *> &getGroup(Group group) {
        return groupedEntities[group];
    }

    Entity &addEntity() {
        Entity *e = new Entity(*this);
        std::unique_ptr<Entity> uPtr{e};
        entities.emplace_back(std::move(uPtr));

        return *e;
    }
};

#endif // ENTITYCOMPONENTSYSTEM_H
