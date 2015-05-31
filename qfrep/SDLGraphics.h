//
//  SDL_graphics.h
//  qfrep
//
//  Created by Quentin Corker_Marin on 31/05/2015.
//  Copyright (c) 2015 Quentin Corker-Marin. All rights reserved.
//

#ifndef __qfrep__SDL_graphics__
#define __qfrep__SDL_graphics__

//includes
#include <stdio.h>
#include <SDL2/SDL.h>
#include <string>

//  a class that contains information on the renderer and basic functions
//  for manipulating what is being shown in the window and refreshing it.
//  Also includes SDL init and free functions in the creator/destructor
//  methods.
class SDLGraphics
{
public:
    SDL_Renderer *renderer; //public renderer to simplify drawing to the renderer
    
    SDLGraphics( char *win_name, int width, int height, SDL_Colour *colour );
    
    ~SDLGraphics();
    
    void clearWindow(); //Clears the window to the background colour
    
    void updateWindow(); //updates the window with information on the renderer
    
    void setBGColour( SDL_Colour *colour ); //sets the background colour of the renderer
    
    int getState(); //get the current stae of the refresh loop (running or not running)
    
    void setState( int n ); //set the state of the refresh loop (running or not running)
    
private:
    int state;
    
    int win_width;
    
    int win_height;
    
    SDL_Colour bg_colour;
    
    SDL_Window *window;
};

#endif /* defined(__qfrep__SDL_graphics__) */
