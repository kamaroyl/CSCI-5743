#pragma once
#include <stdint.h>

typedef struct _graph {

} Graph;

/**
 * Much of the algorithms require graphs in order to generate a random sequence
 */

/**
 *
 * @param c constant stretch
 * @param n number of input bits
 * @return
 */
Graph* generateRandomDisjointCliqueGraph(uint32_t c, uint32_t n);
