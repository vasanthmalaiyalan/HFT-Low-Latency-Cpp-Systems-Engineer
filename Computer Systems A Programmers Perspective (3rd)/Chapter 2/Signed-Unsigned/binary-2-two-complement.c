#include<stdio.h>

// CSAPP Eq 2.3 -> B2T
int B2T(unsigned char bits, int w) {
    int result = 0;

    // MSB (negative weight)
    int sign = (bits >> (w -1)) & 1;
    result -= sign * (1 << (w -1)); // -2^(w-1)

    // remaining bits
    for (int i = 0; i < w-1; i++) {
        int xi = (bits >> i) & 1;
        result += xi * (1 << i);
    }
    return result;
}
int main() {
    printf("B2T4(1011) = %d\n",B2T(0b1011, 4)); // -5
}