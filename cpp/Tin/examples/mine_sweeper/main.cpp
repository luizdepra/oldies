/* 
 * File:   main.cpp
 * Author: RawArkanis
 *
 * Created on June 28, 2014, 10:57 AM
 */

#include <iostream>
#include <memory>

#include "../../sources/application.h"
#include "../../sources/video/window.h"
#include "../../sources/video/texture.h"

using namespace std;
using namespace tin;

/*
 * 
 */
int main(int argc, char** argv)
{    
    auto my_app = make_shared<application>(argc, argv);
    
    window* _window = new window("MineSweeper Example", 100, 100, 1024, 768);  
    
    //Prints errors, if any
    //as of now there's no wrapper around the SDL_GetError
    cout << "Error: " << SDL_GetError() << endl;    
    
    //2 seconds delay to show the window on screen
    //as of now there's no wrapper around the SDL_Delay    
    SDL_Delay(2000);
    
    delete _window;
    
    cout << "Done!" << endl;
    
    return 0;
}
