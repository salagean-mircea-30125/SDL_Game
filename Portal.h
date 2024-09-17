#pragma once

#include "SDL.h"
#include <stdlib.h>
#include "Global.h"

class Portal
{

public:
    static int width;
    static int height;
    SDL_Renderer* ren;
    static float pozx;
    static float pozy;
    static float centru_x;
    static float centru_y;
    static float colt_stg_sus_x;
    static float colt_stg_sus_y;
    static float colt_dr_jos_x;
    static float colt_dr_jos_y;
    virtual void portal_apar();
    void setRender(SDL_Renderer* renderer);
    virtual void check();

};

