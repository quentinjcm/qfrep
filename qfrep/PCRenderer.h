//
//  PCRenderer.h
//  qfrep
//
//  Created by Quentin Corker_Marin on 31/05/2015.
//  Copyright (c) 2015 Quentin Corker-Marin. All rights reserved.
//

#ifndef __qfrep__PCRenderer__
#define __qfrep__PCRenderer__

#include <stdio.h>
#include <SDL2/SDL.h>
#include <vector>

struct coord
{
    int X[3];
};

typedef struct coord coord;

class PCRenderer
{
public:
    PCRenderer( int res,
                int width,
                int height,
                int depth,
                SDL_Colour *colour,
                int (*function)( int arr[3] ) );
    
    ~PCRenderer();
    
    void renderPC( SDL_Renderer *renderer );
    
    void calcPC();
    
    void setPTColour( SDL_Colour *colour );
    
private:
    int grd_width; //width of the grid to be evaluated in pixels
    
    int grd_height; //height of the grid to be evaluated in pixels
    
    int grd_depth; //depth of the grid to be evaluated in pixels
    
    int center_x; // pixel prepresenting x = 0
    
    int center_y; //pixel representing y = 0
    
    int center_z; //pixel representign z = 0
    
    int grd_res; //pixles per sample increment
    
    SDL_Colour pt_colour; //colour for points to be drawn in
    
    std::vector <coord> pt_vec; //vector to hold position of points to be drawn
    
    int (*frep)( int arr[3] ); //function to be evalueate at each point on the grid
};

#endif /* defined(__qfrep__PCRenderer__) */
