#include "Platform.h"
#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#include <vector>
#include <string>
#include "SDL_image.h"
#include <conio.h> 
#include <thread>
#include <chrono>
#include "SDL.h"
#include "Menu.h"
#include "Global.h"
#undef main
#pragma comment(lib, "winmm.lib")
#include "Player.h"



int Platform::width = 150;
int Platform::height = 5;
float Platform::pozx;
float Platform::pozy;
float Platform::colt_stg_sus_x = pozx;
float Platform::colt_stg_sus_y = pozy;
float Platform::colt_dr_jos_x = pozx + width;
float Platform::colt_dr_jos_y = pozy + height;
float Platform::pozitiix[10];
float Platform::pozitiiy[10];



int i=0;

void Platform::Set_poz(float x, float y, int index) {
    Platform::pozx = x;
    Platform::pozitiix[index] = x;
    Platform::pozy = y;
    Platform::pozitiiy[index] = y;
}


void Platform::setRender(SDL_Renderer* renderer)
{
    ren = renderer;
    
}


void Platform::platform_apar()
{
    
    

    SDL_Rect rct;
    rct.x = pozx;
    rct.y = pozy;
    rct.w = width;
    rct.h = height;
    

    SDL_Texture* pl = IMG_LoadTexture(ren, "Imagini/pl.bmp");
    SDL_RenderCopy(ren, pl, NULL, &rct);
    SDL_DestroyTexture(pl);

    /*
    SDL_SetRenderDrawColor(ren, 110, 106, 105, 255);
    SDL_RenderFillRect(ren, &rct);
    */
   
}






