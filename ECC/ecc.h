#ifndef ECC_H_INCLUDED
#define ECC_H_INCLUDED

typedef struct Points{
    int x;
    int y;
}Point;
void doesPointBelongToCurve( Point *const point);
void int_to_bin_digit(unsigned int in, int count, int* out);
int inverse_modulo(int a, int m);

struct Points ECCAddition(Point *const pointP, Point *const pointQ);
struct Points ECCMultiplication(Point *const point, int k);

#endif // ECC_H_INCLUDED
