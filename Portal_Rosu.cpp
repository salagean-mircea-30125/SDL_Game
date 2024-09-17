#include "Portal_Rosu.h"
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
#include "SDL.h"
#include "Menu.h"
#include "Global.h"
#undef main
#pragma comment(lib, "winmm.lib")
#include "Player.h"



float Portal_Rosu::pozx = -30;
float Portal_Rosu::pozy = -30;
float Portal_Rosu::colt_dr_jos_x = pozx + width;
float Portal_Rosu::colt_dr_jos_y = pozy + height;
float Portal_Rosu::centru_x_rosu;
float Portal_Rosu::centru_y_rosu;

void Portal_Rosu::portal_apar() {

    SDL_Rect rct;
    rct.x = pozx;
    rct.y = pozy;
    rct.w = width;
    rct.h = height;

    SDL_Texture* por = IMG_LoadTexture(ren, "Imagini/Portal2.bmp"); 
    SDL_RenderCopy(ren, por, NULL, &rct);
    SDL_DestroyTexture(por);

    centru_x_rosu = pozx + width / 2.0f;
    centru_y_rosu = pozy + height / 2.0f;

}


int teleportCooldown_rosu = 0;

void Portal_Rosu::check() {
    float tolerance = 50;

   
    if (teleportCooldown_rosu > 0) {
        teleportCooldown_rosu -= 1;
        return; 
    }

    if (abs(Player::centru_x - centru_x_rosu) <= tolerance &&
        abs(Player::centru_y - centru_y_rosu) <= tolerance &&
        Player::ok_tp_rosu == 1 && Player::ok_tp == 1)
    {
        Player::ok_tp = 0;
        Player::pozy = Portal::pozy;
        Player::pozx = Portal::pozx;

       
        teleportCooldown_rosu= 100;
    }

    if ((abs(Player::centru_x - centru_x_rosu) > tolerance ||
        abs(Player::centru_y - centru_y_rosu) > tolerance))
    {
        Player::ok_tp_rosu = 1;
    }
}

