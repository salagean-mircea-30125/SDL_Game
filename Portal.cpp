#include "Portal.h"
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
#include "Portal_Rosu.h"
#include "SDL.h"
#include "Menu.h"
#include "Global.h"
#undef main
#pragma comment(lib, "winmm.lib")
#include "Player.h"



int Portal::width = 30;
int Portal::height = 40;
float Portal::pozx = -30;
float Portal::pozy = -30;
float Portal::centru_x;
float Portal::centru_y;
float Portal::colt_dr_jos_x = pozx + width;
float Portal::colt_dr_jos_y = pozy + height;



void Portal::setRender(SDL_Renderer* renderer)
{
    ren = renderer;
    
}

void Portal::portal_apar()
{

    SDL_Rect rct;
    rct.x = pozx;
    rct.y = pozy;
    rct.w = width;
    rct.h = height;
    
    SDL_Texture* po = IMG_LoadTexture(ren, "Imagini/Portal1.bmp");
    SDL_RenderCopy(ren, po, NULL, &rct);
    SDL_DestroyTexture(po);

    centru_x = pozx + width / 2.0f;
    centru_y = pozy + height / 2.0f;
   
}


int teleportCooldown = 0;

void Portal::check() {
    float tolerance = 50;


    if (teleportCooldown > 0) {
        teleportCooldown -= 1; 
        return; 
    }

    if (abs(Player::centru_x - centru_x) <= tolerance &&
        abs(Player::centru_y - centru_y) <= tolerance &&
        Player::ok_tp == 1 && Player::ok_tp_rosu == 1)
    {
        Player::ok_tp_rosu = 0;
        Player::ok_tp = 0;
        Player::pozy = Portal_Rosu::pozy;
        Player::pozx = Portal_Rosu::pozx;

        teleportCooldown = 100;
    }

    if ((abs(Player::centru_x - centru_x) > tolerance ||
        abs(Player::centru_y - centru_y) > tolerance))
    {
        Player::ok_tp = 1;
    }
}

