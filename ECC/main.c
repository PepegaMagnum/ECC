#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ecc.h"


int main() {
    Point a;

    a.x = 15;
    a.y = 13;

    doesPointBelongToCurve( &a );

    Point TwoA = ECCAddition(&a, &a);

    printf("Doubling of point (%d,%d) is (%d,%d)\n", a.x, a.y, TwoA.x, TwoA.y);

    doesPointBelongToCurve( &TwoA );

    Point ThreeA = ECCAddition(&TwoA, &a);

    printf("2A + A = (%d,%d)\n", ThreeA.x, ThreeA.y);

    doesPointBelongToCurve( &ThreeA );

    Point FourA = ECCMultiplication(&a, 4);

    printf("4A = (%d,%d)\n", FourA.x, FourA.y);

    doesPointBelongToCurve( &FourA );

    return 0;
}

