//
//  SDL_graphics.cpp
//  qfrep
//
//  Created by Quentin Corker_Marin on 31/05/2015.
//  Copyright (c) 2015 Quentin Corker-Marin. All rights reserved.
//

//includes
#include "SDLGraphics.h"
#include <SDL2/SDL.h>
#include <string>

//  Initialises SDL before setting up the window and the renderer to work with
//  that window. The background colour for the window is set to the unput colour,
//  and if the colour is NULL then it will default to white.
SDLGraphics::SDLGraphics(char *win_name, int width, int height, SDL_Colour *colour)
{
    window = NULL; //initialising window and renderee to NULL
    renderer = NULL;
    
    SDL_Init( SDL_INIT_EVERYTHING ); //initialising sdl
    
    setBGColour( colour );
    
    window = SDL_CreateWindow( win_name,
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              width,
                              height,
                              SDL_WINDOW_SHOWN) ; // creating window
    
    renderer = SDL_CreateRenderer( window, -1, 0 ); //creating renderer for the window
    
    setState(1); //setting the state to run the refresh loop
}

//  destructor for the SDLGraphics class that destroys the window and the renderer
//  before quiting sdl
SDLGraphics::~SDLGraphics()
{
    SDL_DestroyRenderer( renderer );
    SDL_DestroyWindow( window );
    SDL_Quit();
}

//  sets the drawing colour to the bakcground colour and draws that colour to the
//  entire renderer, overwriting what was on there before
void SDLGraphics::clearWindow()
{
    SDL_SetRenderDrawColor( renderer,
                           bg_colour.r,
                           bg_colour.g,
                           bg_colour.b,
                           bg_colour.a );
    
    SDL_RenderClear( renderer );
}

//  renders the present renderer to the window that it is connected to
void SDLGraphics::updateWindow()
{
    SDL_RenderPresent( renderer );
}

//  sets the background colour to the inputed colour, defaults to white
//  if the input colour is NULL
void SDLGraphics::setBGColour( SDL_Colour *colour )
{
    if( colour == NULL ){
        bg_colour.r = 255;
        bg_colour.g = 255;
        bg_colour.b = 255;
        bg_colour.a = 255;
    }
    else{
        bg_colour.r = colour->r;
        bg_colour.g = colour->g;
        bg_colour.b = colour->b;
        bg_colour.a = colour->a;
    }
}

int SDLGraphics::getState()
{
    return state;
}

void SDLGraphics::setState(int n)
{
    state = n;
}











