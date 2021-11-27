#pragma once

#define MAX_POLYNOMIAL_LENGTH 256

/**
 * Representation of a matrix in
 */
typedef struct _Polynomial {
    uint16_t coefficients[MAX_POLYNOMIAL_LENGTH];
} Polynomial;



void polynomial_addition(Polynomial* C, Polynomial* A, Polynomial* B);
void polynomial_subtraction(Polynomial* C, Polynomial* A, Polynomial* B);
void montgomery_reduction();