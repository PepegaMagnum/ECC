#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ecc.h"

#define MOD(a,b) ((((a)%(b))+(b))%(b))

void doesPointBelongToCurve( Point *const point){
    if ( ( (int)( pow( point -> x, 3 ) + 7 - pow( point -> y , 2 ) ) % 17 ) == 0 ){
        printf("Point (%d,%d) belongs to the curve!\n", point -> x, point -> y);
    }else{
        printf("Point (%d,%d) does not belong to the curve!\n ", point -> x, point -> y);
    }
}

struct Points ECCAddition(Point *const pointP, Point *const pointQ){
    int x1 = pointP->x;
    int y1 = pointP->y;

    int x2 = pointQ->x;
    int y2 = pointQ->y;
    int m;

    if(x1 == x2){

        m = MOD((3*x1*x1),17)*inverse_modulo(2*y1, 17);
    }
    else{
        m = MOD(y2 - y1,17)*inverse_modulo( x2-x1, 17);
    }

    Point res = {};

    int x3 = m*m -x1-x2;
    int y3 = y1 + m*(x3 - x1);

    res.x = MOD(x3,17);
    res.y = MOD(-y3,17);

    return res;
}

struct Points ECCMultiplication(Point *const point, int k){
    Point res = *point;

    if(k == 1){
        return res;
    }

    for(int i = 1; i<k; i++){
        res = ECCAddition(&res, point);
    }
    return res;
}


int inverse_modulo(int a, int m){
    for(int x = 1; x < m; x++){
        if (  ( (a%m) * (x%m) ) % m == 1){
            return x;
        }
    }
}

void int_to_bin_digit(unsigned int in, int count, int* out)
{
    unsigned int mask = 1U << (count-1);
    int i;
    for (i = 0; i < count; i++) {
        out[i] = (in & mask) ? 1 : 0;
        in <<= 1;
    }
}
