#pragma once

#include <SDL2/SDL.h>
#include <string>
#include "SDLGameObject.h"
#include "LoaderParams.h"

class Background : public SDLGameObject
{
public:
    Background(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
};