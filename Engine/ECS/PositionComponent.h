//
// Created by gordo on 24.02.20.
//

#ifndef ENGIPIXI_POSITIONCOMPONENT_H
#define ENGIPIXI_POSITIONCOMPONENT_H

#if defined(__linux__) || defined(__APPLE__)
    #include "SDL2/SDL.h"
#elif _WIN32
    #include "SDL.h"
#endif

#include "EntityComponentSystem.h"
//#include "Components.h"
#include "../Math/Vector2D.h"



class PositionComponent : public Component {
public:
    Vector2D position;

    PositionComponent() { position = {0, 0}; }

    PositionComponent(int x, int y);

    PositionComponent(Vector2D p) : position(p) {}

    const Vector2D &getPosition() const {
        return position;
    }

    bool isBeforePlayer(const Vector2D &p, const SDL_Rect &playerRect) const;


    bool isAfterPlayer(const Vector2D &p, const SDL_Rect &playerRect) const;

    [[nodiscard]] float x() const;

    [[nodiscard]] float y() const;

    void init() override;

    void update() override;

    void draw() override;

    ~PositionComponent() {

    }
};


#endif //ENGIPIXI_POSITIONCOMPONENT_H
