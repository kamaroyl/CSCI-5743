#include "polynomial.h"

void polynomial_addition(Polynomial* C, Polynomial* A, Polynomial* B) {
    for (int i = 0; i < MAX_POLYNOMIAL_LENGTH; ++i) {
        C->coefficients[i] = A->coefficients[i] + B->coefficients[i];
    }
}

void polynomial_subtraction(Polynomial* C, Polynomial* A, Polynomial* B) {
    for (int i = 0; i < MAX_POLYNOMIAL_LENGTH; ++i) {
        C->coefficients[i] = A->coefficients[i] - B->coefficients[i];
    }
}

void montgomery_reduction() {

}

