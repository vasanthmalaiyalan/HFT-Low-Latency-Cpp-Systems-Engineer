#include<stdio.h>
#include<stdint.h>

// show binary (8-bit for simplicity)
void show_bits(unsigned char x) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (x >> i) & 1);
    }
}

// simulate w-bit truncation
unsigned truncate(unsigned x, int w) {
    return x & ((1U << w) -1);
}

int main() {

    printf("======== Signed vs Unsigned Multiplication =========\n\n");

    int sx = -3;
    int sy = 3;

    unsigned ux = (unsigned char)sx; //same bits
    unsigned uy = (unsigned char)sy;

    printf("Signed values:\n");
    printf("x = %d, y = %d\n", sx, sy);

    printf("\nUnsigned view (same bits):\n");
    printf("x = %u, y = %u\n", ux, uy);

    // full multiplication
    int signed_prod = sx * sy;
    unsigned unsigned_prod = ux * uy;

    printf("\nFull multiplication:\n");
    printf("Signed: %d * %d = %d\n", sx, sy, signed_prod);
    printf("Unsigned: %u * %u = %u\n", ux, uy, unsigned_prod);

    // simulate 3-bit system
    int w = 3;

    unsigned trunc_signed = truncate((unsigned)signed_prod, w);
    unsigned trunc_unsigned = truncate(unsigned_prod, w);

    printf("\nAfter truncation to %d bits:\n", w);

    printf("Signed result (bits):   ");
    show_bits(trunc_signed);
    printf(" -> %d\n", (int)(signed char)(trunc_signed << 5) >> 5); //signed extend

    printf("Unsigned result (bits): ");
    show_bits(trunc_unsigned);
    printf(" -> %u\n", trunc_unsigned);

    // compapre bits
    if (trunc_signed == trunc_unsigned)
        printf("\n Bit-level result Same!\n");
    else
        printf("\n Different!\n");
        
    return 0;    
}
