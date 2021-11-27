#include "utils.h"

EuclideanAlgorithmReturn* extended_euclidean_algorithm(uint64_t a, uint64_t b) {
    EuclideanAlgorithmReturn* response = (EuclideanAlgorithmReturn*) malloc(sizeof(EuclideanAlgorithmReturn));
    uint64_t r, old_r, s, old_s, t, old_t, tmp;
    old_r = a;
    r = b;
    old_s = 1;
    s = 0;
    old_t = 0;
    t = 1;

    while(r != 0) {
        quotient = uint32_t(old_r / r);
        tmp = r;
        r = old_r - quotient * tmp;
        old_r = tmp;
        tmp = s;
        s = old_s - quotient * tmp;
        old_s = tmp;
        tmp = t;
        t = old_t - quotient * tmp;
        old_t = tmp;
    }
    response->bezout[0] = old_s;
    response->bezout[1] = old_t;
    response->gcd = old_r;
    response->quotient[0] = s;
    response->quotient[1] = t;
    return response;
}
