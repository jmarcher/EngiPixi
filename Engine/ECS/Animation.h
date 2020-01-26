#ifndef ANIMATION_H
#define ANIMATION_H

struct Animation {
    int aIndex;
    int aFrames;
    int aSpeed;
    Animation(){
        this->aIndex = 0;
        this->aFrames = 1;
        this->aSpeed = 100;
    }
    Animation(int mIndex, int mFrames, int mSpeed) {
        aIndex = mIndex;
        aFrames = mFrames;
        aSpeed = mSpeed;
    }
};

#endif // ANIMATION_H
