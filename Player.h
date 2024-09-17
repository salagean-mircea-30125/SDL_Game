#pragma once
#include "SDL.h"
#include <stdlib.h>
#include "Global.h"
#include "SDL_image.h"

class Player
{
private:

    SDL_Renderer* ren;  
    SDL_Texture* plr;
    bool grounded;

public:  
    static int width;
    static int height;
    static float pozx;
    static float pozy;
    static float centru_x;
    static float centru_y;
    float colt_stg_sus_x = pozx;
    float colt_stg_sus_y = pozy;
    static float colt_dr_jos_x;
    static int ok_tp;
    static int ok_tp_rosu;
    static float colt_dr_jos_y;
    void apar();  
    void setRender(SDL_Renderer* renderer);
    void miscare();
    void gravitatie();
    void check();
};
