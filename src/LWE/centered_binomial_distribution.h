#pragma once
#include "polynomial.h"


/*
 * Binomial Distribution cumulant generating function:
 * Lambda(eta) = n log(1 + e ^ eta)
 */
static void centered_binomial_distribution(Polynomial *error, const uint8_t buffer[2*POLYNOMIAL_LENGTH/4])
{
    unsigned int i,j;
    uint32_t t,d;
    int16_t a,b;

    for(i=0;i<POLYNOMIAL_LENGTH/8;i++) {
        t  = load32_littleendian(buffer+4*i);
        d  = t & 0x55555555;
        d += (t>>1) & 0x55555555;

        for(j=0;j<8;j++) {
            a = (d >> (4*j+0)) & 0x3; // 0000 0000 0000 0111
            b = (d >> (4*j+2)) & 0x3;
            error->coefficients[8*i+j] = a - b;
        }
    }
}

static uint16_t barrett_reduce(uint16_t a) {


}