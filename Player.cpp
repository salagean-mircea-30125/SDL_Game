#include "Player.h"
#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#include "SDL_image.h"
#include "Platform.h"
#include <vector>
#include <string>
#include "Portal.h"
#include <thread>
#include <chrono>
#include "SDL.h"


int Player::width = 40;
int Player::height = 40;
float Player::pozx=0;
float Player::pozy=800;
float Player::colt_dr_jos_x;
int Player::ok_tp_rosu = 1;
int Player::ok_tp = 1;
float Player::colt_dr_jos_y;
float Player::centru_x = (colt_dr_jos_x - pozx) / 2;
float Player::centru_y = (colt_dr_jos_y - pozy) / 2;

void Player::setRender(SDL_Renderer* renderer)
{
    ren = renderer;
}




void Player::apar()
{

    SDL_Rect rct;
    rct.x = pozx;
    rct.y = pozy;
    rct.w = width;
    rct.h = height;

    
    SDL_RenderCopy(ren, plr, NULL, &rct);
    SDL_DestroyTexture(plr);
    /*
    SDL_SetRenderDrawColor(ren, 0, 255, 0, 255);
    SDL_RenderFillRect(ren, &rct);
    */
    
    centru_x = pozx + width / 2.0f;
    centru_y = pozy + height / 2.0f;
}

void Player::miscare() {

    SDL_DestroyTexture(plr);
    plr = IMG_LoadTexture(ren, "Imagini/viking.bmp");
   

    if (GetAsyncKeyState('D') < 0)
    {
        plr = IMG_LoadTexture(ren, "Imagini/viking_dr.bmp");
        pozx += 0.7;
        apar();
        SDL_DestroyTexture(plr);
    }
    if (GetAsyncKeyState('D') == 0)
    {
        pozx = pozx;
        
    }


    if (GetAsyncKeyState('A') < 0)
    {
        plr = IMG_LoadTexture(ren, "Imagini/viking_st.bmp");
        pozx -= 0.7;
        apar();
        SDL_DestroyTexture(plr);
    }
    if (GetAsyncKeyState('A') == 0)
    {
        pozx = pozx;
        
    }


    if (GetAsyncKeyState('W') < 0 && grounded == true)
    {
           
            pozy -= 150;
            apar();
          
    }
    if (GetAsyncKeyState('W') == 0)
    {
        pozy = pozy;
    }

    if (pozy < 0)
        pozy = 0;

    if (pozx < 0)
        pozx = 0;

    if (pozy > scr_h-height)
        pozy = scr_h- height;

    if (pozx > scr_w- height)
        pozx = scr_w- height;

    gravitatie();
    check();
    
}

void Player::gravitatie() 
{
    if (pozy < scr_h - height)
    {
        
        pozy += 0.1 ;
        apar();
        
    }
        
}



void Player::check()
{
    const float margin = 0.1;
    grounded = false;

    for (int i = 0; i < 10; i++)
    {
        if (abs(pozy - (Platform::pozitiiy[i] - height)) < margin &&
            pozx > Platform::pozitiix[i] - 30 &&
            pozx < Platform::pozitiix[i] + Platform::width - width/4)
        {
          
            pozy = Platform::pozitiiy[i] - height - margin ;
            grounded = true;
            break;
            
        }
       
    }

    if (pozy == scr_h - height)
        grounded = true;



}



