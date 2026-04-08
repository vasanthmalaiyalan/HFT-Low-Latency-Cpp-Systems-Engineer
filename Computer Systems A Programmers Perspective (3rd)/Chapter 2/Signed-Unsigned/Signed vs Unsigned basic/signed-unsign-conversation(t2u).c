#include<stdio.h>

void show_bits(int bits) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (bits >> i) & 1);
    }
    printf("\n");
}

int main() {
    int x = -2;
    unsigned int u = (unsigned int)x;// conversation
    show_bits(x);
    
    printf("x = %d\n", x);
    printf("After conversation u = %u\n", u);
}

/*

x = -1
After conversation u = 4294967295

*/