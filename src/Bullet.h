#pragma once

#include <SDL2/SDL.h>
#include <string>
#include "SDLGameObject.h"
#include "LoaderParams.h"

class Bullet : public SDLGameObject
{
public:
    Bullet(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
};