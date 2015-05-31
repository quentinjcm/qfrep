//
//  main.cpp
//  qfrep
//
//  Created by Quentin Corker_Marin on 31/05/2015.
//  Copyright (c) 2015 Quentin Corker-Marin. All rights reserved.
//

#include <iostream>
#include "SDLGraphics.h"
#include "PCRenderer.h"
#include "primatives.h"
#include "operations.h"

int circle( int X[3] )
{
    int center_a[3] = { 0, 0, 0 };
    int center_b[3] = {100, 100, 100};
    int radius_a = 200;
    int radius_b = 150;
    
    int out_a = PRIM_Sphere( X, center_a, radius_a);
    
    int out_b = PRIM_Sphere(X, center_b, radius_b);
    
    int un = frepIntersection(out_a, out_b);
    return un;
}

int main(int argc, const char * argv[])
{
    SDLGraphics *graphics = NULL;
    char win_name[6] = "qfrep";
    char *name = win_name;
    
    PCRenderer *point_cloud = NULL;
    
    int (*circ)(int X[3]) = NULL;
    circ = &circle;
    
    graphics = new SDLGraphics(name, 800, 800, NULL);
    point_cloud = new PCRenderer(5, 800, 800, 800, NULL, circ);
    
    point_cloud->calcPC();
    
    while( graphics->getState() ){
        SDL_Event inc_event;
        while( SDL_PollEvent( &inc_event ) ){
            switch( inc_event.type ){
                case SDL_QUIT: graphics->setState(0); break;
            }
        }
        graphics->clearWindow();
        point_cloud->renderPC( graphics->renderer );
        graphics->updateWindow();
        SDL_Delay(10);
    }
    
    delete point_cloud;
    delete graphics;
    return 0;
}

