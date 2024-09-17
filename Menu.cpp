#include "Menu.h"
#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#include <vector>
#include <string>
#include <conio.h> 
#include <thread>
#include <chrono>
#include "SDL.h"
#undef main
#pragma comment(lib, "winmm.lib")


int showMenu() 
{
    int select;

    while (true) 
    {
        system("cls");
        std::cout << "(1) -> start\n";
        std::cout << "(2) -> tutorial\n";
        std::cout << "(3) -> volume\n";
        std::cout << "(4) -> exit\n";  
        std::cin >> select;

        if (select == 1) 
        {
            std::cout << "Acuma boss...\n";
            break;
        }

        if (select == 2) 
        {
            while (true) 
            {
                system("cls");
                std::cout << "W A S D esti prost? \n\n";
                std::cout << "(1) -> back \n";
                std::cin >> select;

                if (select == 1) 
                {
                    break;  
                }
            }
        }


        if (select == 3) 
        {
            while (true) 
            {
                system("cls");
                std::cout << "Alege volum de la 1 la 10: \n\n";
                std::cout << "(1) -> back \n";
                std::cin >> select;

                int vol;

                if (select == 1) 
                {
                    break;
                }
       
            }
        }

        if (select == 4) 
        {
            std::cout << "Gata iesim...\n";
            exit(0);
        }
      
    }
}