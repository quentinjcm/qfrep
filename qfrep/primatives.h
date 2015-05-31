//
//  primatives.h
//  qfrep
//
//  Created by Quentin Corker_Marin on 31/05/2015.
//  Copyright (c) 2015 Quentin Corker-Marin. All rights reserved.
//

#ifndef __qfrep__primatives__
#define __qfrep__primatives__

#include <stdio.h>

int PRIM_Circle( int X[3], int center[3], int radius );

int PRIM_HalfPlane( int X[3], int a, int b, int d );

int PRIM_Square( int X[3], int center[3], int side_len);

int PRIM_Sphere( int X[3], int center[3], int radius );

#endif /* defined(__qfrep__primatives__) */
