#ifndef ANIMATION_H
#define ANIMATION_H

struct Animation {
    int aIndex;
    int aFrames;
    int aSpeed;
    Animation(){}
    Animation(int mIndex, int mFrames, int mSpeed) {
        aIndex = mIndex;
        aFrames = mFrames;
        aSpeed = mSpeed;
    }
};

#endif // ANIMATION_H
