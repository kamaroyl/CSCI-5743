#pragma once

typedef struct Vector {
    int16_t* data;
    size_t length;
} Vector;

typedef struct Matrix {
    Vector* data;
    size_t rowLength;
    size_t columnLength;
} Matrix;