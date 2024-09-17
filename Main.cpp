#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#include <vector>
#include <string>
#include <conio.h> 
#include <thread>
#include <chrono>
#include "Player.h"
#include "SDL.h"
#include "Menu.h"
#include "Global.h"
#include "Portal.h"
#include "Portal_Rosu.h"
#include "SDL_image.h"
#include "Platform.h"
#undef main
#pragma comment(lib, "User32.lib")
#pragma comment(lib, "winmm.lib")

int joinable=1;

void playMusic() {

    std::vector<std::string> muzica = {
       "open \"Muzica\\Eyeless.mp3\" type mpegvideo alias mp3",
       "open \"Muzica\\Sic.mp3\" type mpegvideo alias mp3",
       "open \"Muzica\\Surfaces.mp3\" type mpegvideo alias mp3",
       "open \"Muzica\\Broken.mp3\" type mpegvideo alias mp3",
       "open \"Muzica\\ANewLevel.mp3\" type mpegvideo alias mp3",
       "open \"Muzica\\Vacariidiniad.mp3\" type mpegvideo alias mp3"
    };

    srand(time(NULL));

    int i;

    while (true)
    {

        i = rand() % muzica.size();

        mciSendStringA(muzica[i].c_str(), NULL, 0, NULL);
        mciSendString(TEXT("setaudio mp3 volume to 200"), NULL, 0, NULL);
        mciSendString(TEXT("play mp3 wait"), NULL, 0, NULL);
        mciSendString(TEXT("close mp3"), NULL, 0, NULL);
        joinable = 0;
    }
}

float scr_w = 1800;
float scr_h = 900;
int ok_portal1 = 0;
int ok_portal2 = 0;


int main() {

    
    std::thread musicThread(playMusic);

    if (joinable == 0)
    {
        musicThread.join();
        joinable = 1;
    }
    
    showMenu();

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* win = SDL_CreateWindow("c0@i3 da melc", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, scr_w, scr_h,0);
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    SDL_Texture* plr = IMG_LoadTexture(ren, "Imagini/viking.bmp");
    SDL_Texture* tex = IMG_LoadTexture(ren, "\Imagini\\sky.bmp");
    

    bool mere = true;
    SDL_Event e;
   
   

    Player gicu;
    int nr_platforme = 3;
    Platform platforme[3];
    Portal portal1;
    Portal_Rosu portal2;

    for (int i = 0; i < nr_platforme; i++)
    {
        platforme[i].setRender(ren);
    }

    gicu.setRender(ren);
    portal1.setRender(ren);
    portal2.setRender(ren);


    platforme[0].Set_poz(700, 720, 0);
    platforme[1].Set_poz(500, 820, 1);
    platforme[2].Set_poz(900, 620, 2);



    
    while (mere) {
        

        SDL_RenderClear(ren);
        SDL_RenderCopy(ren, tex, NULL, NULL);
        

        for (int j = 0; j < nr_platforme; j++)
        {
            platforme[j].Set_poz(Platform::pozitiix[j], Platform::pozitiiy[j], j);
            platforme[j].platform_apar();
        }
      
        portal1.setRender(ren);
        portal2.setRender(ren);


        portal1.portal_apar();
        portal2.portal_apar();


        portal1.check();
        portal2.check();

        gicu.apar();
        gicu.miscare();


        while (SDL_PollEvent(&e))
        {
            switch (e.type) {
            case SDL_QUIT:
                mere = false;
                break;
            default:
                break;
            }

            if (SDL_MOUSEBUTTONDOWN == e.type)
            {
                if (SDL_BUTTON_LEFT == e.button.button)
                {
                
                    int x, y;
                    SDL_GetMouseState(&x, &y);
                    portal1.pozx = float(x-15);
                    portal1.pozy = float(y-20);


                }

            }

            if (SDL_MOUSEBUTTONDOWN == e.type)
            {
                if (SDL_BUTTON_RIGHT == e.button.button)
                {
                    
                    int x, y;

                    SDL_GetMouseState(&x, &y);
                    portal2.pozx = float(x-15);
                    portal2.pozy = float(y-20);
                }

            }


        }
   

        SDL_RenderPresent(ren);      
 
    }


    SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();

    



    return 0;
}