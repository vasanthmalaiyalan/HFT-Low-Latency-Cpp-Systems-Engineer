#include<stdio.h>

//CSAPP Eq 2.1 -> B2U
unsigned int B2U(unsigned char bits, int w) {
    unsigned result = 0;

    for (int i = 0; i < w; i++) {
        int xi = (bits >> i) & 1; // bit 1
        result += xi * (1 << i); //xi x 2^i
    }
    return result;
}
int main() {
    printf("B2U4(0101) = %u\n", B2U(0b0101, 4)); // 5
}