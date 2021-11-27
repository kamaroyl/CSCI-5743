#pragma once
typedef struct _EuclideanAlgorithmReturn {
    uint64_t bezout[2];
    uint64_t gcd;
    uint64_t quotient[2];
} EuclideanAlgorithmReturn;

EuclideanAlgorithmReturn* extended_euclidean_algorithm(uint64_t a, uint64_t b);