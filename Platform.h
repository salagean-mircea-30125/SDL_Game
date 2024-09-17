#pragma once
#include "SDL.h"
#include <stdlib.h>
#include "Global.h"

class Platform
{
public: 
    static int width;
    static int height;
	SDL_Renderer* ren;
    static float pozx;
    static float pozy;
    static float colt_stg_sus_x;
    static float colt_stg_sus_y;
    static float colt_dr_jos_x;
    static float pozitiix[10];
    static float pozitiiy[10];
    static float colt_dr_jos_y;
    void Set_poz(float x, float y, int index);
    void platform_apar();
    void setRender(SDL_Renderer* renderer);

};

