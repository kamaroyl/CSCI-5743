/**
 *     MIT License

    Copyright (c) Microsoft Corporation. All rights reserved.

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE
 */
 
#include "Gaussian.h"

// Taken from FrodoKEM
void sampleGaussianNoise(uint16_t *s, const size_t n, const uint16_t* CDF_LUT, uint8_t cdfLutLength)
{ // Fills vector s with n samples from the noise distribution which requires 16 bits to sample.
    // The distribution is specified by its CDF.
    // Input: pseudo-random values (2*n bytes) passed in s. The input is overwritten by the output.
    unsigned int i, j;
    uint16_t sample, prnd, sign = 0;
    for (i = 0; i < n; ++i) {
        sample = 0;
        prnd = s[i] >> 1;    // Drop the least significant bit
        sign = s[i] & 0x1;    // Pick the least significant bit

        // No need to compare with the last value.
        for (j = 0; j < (unsigned int)(cdfLutLength - 1); j++) {
            // Constant time comparison: 1 if CDF_TABLE[j] < s, 0 otherwise. Uses the fact that CDF_TABLE[j] and s fit in 15 bits.
            sample += (uint16_t)(CDF_LUT[j] - prnd) >> 15;
        }
        // Assuming that sign is either 0 or 1, flips sample iff sign = 1
        s[i] = ((-sign) ^ sample) + sign;
    }
}