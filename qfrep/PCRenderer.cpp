//
//  PCRenderer.cpp
//  qfrep
//
//  Created by Quentin Corker_Marin on 31/05/2015.
//  Copyright (c) 2015 Quentin Corker-Marin. All rights reserved.
//

#include "PCRenderer.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <vector>

PCRenderer::PCRenderer( int res, int width, int height, int depth, SDL_Colour *colour, int (*function)( int arr[3] ) )
{
    grd_res = res;
    grd_width = width;
    grd_height = height;
    grd_depth  = depth;
    
    setPTColour( colour );
    
    frep = function;
}

PCRenderer::~PCRenderer()
{

}

void PCRenderer::calcPC()
{
    
    int center_x = grd_width/2 + 1;
    int center_y = grd_height/2 + 1;
    int center_z = grd_depth/2 + 1;
    
    int x, y, z;
    
    for( x = 0; x < grd_width; x += grd_res){
        for( y = 0; y < grd_height; y += grd_res){
            for( z = 0; z < grd_depth; z += grd_res){
                int coord[3] = { x-center_x, y-center_y, z-center_z };
                if( frep( coord ) >= 0 ){
                    pt_vec.push_back( {x, y, z} ); //if changed to coord[a] (not x) then they will represent
                                                   //the coordinate relative to the origin as opposed to relative
                                                   //to the screen
                }
            }
        }
    }
}

void PCRenderer::renderPC( SDL_Renderer *renderer )
{
    std::vector<coord>::iterator i;
    
    SDL_SetRenderDrawColor(renderer, pt_colour.r, pt_colour.g, pt_colour.b, pt_colour.a);
    
    for( i = pt_vec.begin(); i != pt_vec.end(); ++i ){
        SDL_RenderDrawPoint( renderer, i->X[0], i->X[1] );
    }
    
}

void PCRenderer::setPTColour( SDL_Colour *colour )
{
    if( colour == NULL ){
        pt_colour.r = 0;
        pt_colour.g = 0;
        pt_colour.b = 0;
        pt_colour.a = 255;
    }
    else{
        pt_colour.r = colour->r;
        pt_colour.g = colour->g;
        pt_colour.b = colour->b;
        pt_colour.a = colour->a;
    }
}
