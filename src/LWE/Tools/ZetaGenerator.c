#include <stdio.h>
#include <stdint.h>
/*
#define MONTGOMERY -1044
#define PRIME 3329
#define PRIME_OVER_TWO 1664
#define NEGATIVE_PRIME_OVER_TWO -1664
#define PRIME_INVERSE -3327
#define PRIME_ROOT_OF_UNITY 17
*/
#define MONTGOMERY -17922
#define PRIME 41729
#define PRIME_OVER_TWO 20864
#define NEGATIVE_PRIME_OVER_TWO -20864
#define PRIME_INVERSE -17920
#define PRIME_ROOT_OF_UNITY 89

int16_t zetas[128] = {0};


static const uint8_t tree[128] = {
        0, 64, 32,  96, 16, 80, 48, 112,  8, 72, 40, 104, 24, 88, 56, 120,
        4, 68, 36, 100, 20, 84, 52, 116, 12, 76, 44, 108, 28, 92, 60, 124,
        2, 66, 34,  98, 18, 82, 50, 114, 10, 74, 42, 106, 26, 90, 58, 122,
        6, 70, 38, 102, 22, 86, 54, 118, 14, 78, 46, 110, 30, 94, 62, 126,
        1, 65, 33,  97, 17, 81, 49, 113,  9, 73, 41, 105, 25, 89, 57, 121,
        5, 69, 37, 101, 21, 85, 53, 117, 13, 77, 45, 109, 29, 93, 61, 125,
        3, 67, 35,  99, 19, 83, 51, 115, 11, 75, 43, 107, 27, 91, 59, 123,
        7, 71, 39, 103, 23, 87, 55, 119, 15, 79, 47, 111, 31, 95, 63, 127
};

int16_t montgomery_reduce(int32_t a)
{
    int16_t t;

    t = (int16_t)a * PRIME_INVERSE;
    t = (a - (int32_t)t * PRIME) >> 16;
    return t;
}

static int16_t fqmul(int16_t a, int16_t b) {
    return montgomery_reduce((int32_t)a*b);
}

void init_ntt() {
    unsigned int i;
    int16_t tmp[128];

    tmp[0] = MONTGOMERY;
    for(i=1;i<128;i++)
        tmp[i] = fqmul(tmp[i-1],MONTGOMERY * PRIME_ROOT_OF_UNITY % PRIME);

    for(i=0;i<128;i++) {
        //printf("i = %d, ", i);
        //printf("trees[%d] = %d, ", i, tree[i]);
        //printf("tmp[tree[%d]] = %d\n", i, tmp[tree[i]]);
        zetas[i] = tmp[tree[i]];
        //printf("Before Zeta[%d] = %d, ", i, zetas[i]);
        if(zetas[i] > PRIME_OVER_TWO)
            //printf(" zetas greater than prime over two, ");
            zetas[i] -= PRIME;
        if(zetas[i] < NEGATIVE_PRIME_OVER_TWO)
            //printf(" Zetas less than negative prime over two, ");
            zetas[i] += PRIME;
        printf("%d\n", zetas[i]);
    }
}

int main(void) {
    init_ntt();
    return 0;
}