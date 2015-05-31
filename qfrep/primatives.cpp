//
//  primatives.cpp
//  qfrep
//
//  Created by Quentin Corker_Marin on 31/05/2015.
//  Copyright (c) 2015 Quentin Corker-Marin. All rights reserved.
//

#include "primatives.h"
#include <cmath>

int PRIM_Circle( int X[3], int center[3], int radius )
{
    int result = 0;
    
    int x = X[0];
    int y = X[1];
    
    int i = center[0];
    int j = center[1];
    
    result = pow( radius, 2 ) - pow( x-i, 2) - pow( y-j, 2);
    
    return result;
}

int PRIM_Sphere( int X[3], int center[3], int radius )
{
    int result = 0;
    
    int x = X[0];
    int y = X[1];
    int z = X[2];
    
    int i = center[0];
    int j = center[1];
    int k = center[2];
    
    result = pow( radius, 2 ) - pow( x-i, 2) - pow( y-j, 2) - pow( z-k, 2);
    
    return result;
}
