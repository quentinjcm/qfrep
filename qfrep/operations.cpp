//
//  operations.cpp
//  qfrep
//
//  Created by Quentin Corker_Marin on 31/05/2015.
//  Copyright (c) 2015 Quentin Corker-Marin. All rights reserved.
//

#include "operations.h"
#include <math.h>

int frepUnion( int a, int b )
{
    double hyp = hypot( (double)a, (double)b );
    
    return (int)( a + b + hyp );
}

int frepIntersection( int a, int b )
{
    double hyp = hypot( (double)a, (double)b );
    
    return (int)( a + b - hyp );
}