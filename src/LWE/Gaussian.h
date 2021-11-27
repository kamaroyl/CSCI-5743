#pragma once
// s = sqrt(2 * pi) * sigma
// Approximate discrete gaussian via continuous gaussian, sample continuous gaussian with a certain standard deviation
// Round
// lookup table such that the lookup table entries are defined:
//T_chi(0) = 2^(len_chi - 1) * chi(0) - 1
//T_chi(x) = T_chi(0) + 2^(len_chi) * (chi(1) + chi(2) + ... chi(z)) such that z < s

