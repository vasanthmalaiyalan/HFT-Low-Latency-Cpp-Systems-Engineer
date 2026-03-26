#include<stdio.h>
#include<stdint.h>

// B2U function bit vector to unsigned
unsigned int B2U(unsigned char bits, int w) {
    unsigned int result = 0;
    for (int i = 0; i < w; i++) {
        int xi = (bits >> i) & 1;
        result += xi * (1 << i); //xi x 2^i 
    }
    return result;
}

void show_B2U(unsigned char bits, int w) {
    printf("[");
    for (int i = w-1; i >= 0; i--)
        printf("%d", (bits >> i) & 1);
    printf("] = ");

    //each bits contribution
    int first = 1;
    for (int i = w-1; i >=0; i--) {
        int xi = (bits >> i) & 1;
        if (!first) printf(" + ");
        printf("%dx2^%d", xi, i);
        first = 0;
    }
    printf(" = %u\n", B2U(bits,w));
}

int main() {

    // =======================================
    // Book Exact Examples - B2U4
    // =======================================
    printf("==== BOOK EXACT: B2U4 Examples === \n\n");

    // B2U([0001]) = 0x2^3 + 0x2^2 + 0x2^1 + 0x2^0 = 1
    printf("B2U4");
    show_B2U(0b0001, 4);
    printf(" = 0+0+0+1 = 1\n\n");

    // B2U4([0101]) = 0x2^3 + 0x2^2 + 1x2^1 + 1x2^0 =5
    printf("'B2U4");
    show_B2U(0b0101, 4);
    printf(" = 0+4+0+1");
    printf(" = 0+4+0+1 = 5\n\n");

    // B2U([1011]) = 1x2^3 + 0x2^2 + 1x2^1 + 1x2^0 = 11
    printf("B2U");
    show_B2U(0b1011, 4);
    printf(" = 8+0+2+1 = 11\n\n");

    // b2U([1111]) = 1x2^3 + 1x2^2 + 1x2^1 + 1x2^0 = 15
    printf("B2U");
    show_B2U(0b1111, 4);
    printf(" = 8+4+2+1 = 15\n\n");

    // =======================================
    // RANGE - min and max
    // =========================================
    printf("====== Range (w=4 bits) ===\n\n");

    printf("Minimum: [0000] = 0\n");
    printf("  all bits = 0, nothing to add\n\n");

    printf("Maximum: [1111] = 2^4 -1 = 16 - 1 = 15\n");
    printf(" UMax4 = 2^w -1 = %d\n\n",(1 << 4) -1);//value consider default int like 4 bytes = 32 bits
    
    // General Formula
    printf("General UMaxw = 2^w - 1\n");
    printf(" w=4: UMax = %d\n", (1 << 4) - 1); // 15
    printf(" w=8: UMax = %d\n", (1 << 8) - 1); //255
    printf(" w=16: UMax = %d\n", (1 << 16) - 1); // 65535
    printf(" w=32: UMax = %d\n", (1U << 31) * 2-1); // 4294967295

    // ========================================
    // ALL 4-BIT UNSIGNED VALUES
    // ==========================================
    printf("=== ALL 4-BIT UNSIGNED VALUES ===\n\n");
    printf("Bits    Value\n");
    printf("_____________\n");
    for (int i = 0; i <= 15; i++) {
        printf("[");
        for (int j = 3; j >= 0; j--) {
            printf("%d", (i >> j) & 1);   
        }
        printf("] = %2d\n", i); 
    }

    // ========================================
    // BIJECTION -- One-to-one and onto
    // =========================================
    printf("\n=== BIJECTION (Uniqueness) ====\n\n");

    printf("'B2U is aBIJECTION: \n");
    printf(" Every bit pattern -> unique number\n");
    printf(" Every number -> unique bit pattern\n\n");

    printf("Example: decimal 11\n");
    printf(" Only One 4-bit pattern = [1011]\n");
    printf(" No other pattern gives 11\n\n");

    printf("B2Uw : {0,1}^w -> {0, ......,2^w-1} (bits to number)\n");
    printf("U2Bw : {0,......, 2^w-1} -> {0,1}^w (number to bits)\n");
    printf("These are INVERSE function of each other\n\n");

    // Demonstrate: B2U then U2B gives back original
    printf("=== B2U then U2B = original ====\n");
    printf("Start: [1011]\n");
    printf("B2U([1011]) = 11\n");
    printf("U2B(11) = [");
    for (int i = 3; i >= 0; i--) {
        printf("%d", (11 >> i) & 1);
    printf("] <- same as original! \n\n");    
    }

    // =============================================
// Figure 2.12 — bar length visualization
// =============================================
printf("=== FIGURE 2.12 — bit contribution ===\n\n");
printf("Position  Power   Bar length  Contributes if bit=1\n");
printf("────────────────────────────────────────────────\n");
printf("bit 3     2^3     ████████    8\n");
printf("bit 2     2^2     ████        4\n");
printf("bit 1     2^1     ██          2\n");
printf("bit 0     2^0     █           1\n\n");

printf("[1011]: bit3=1, bit2=0, bit1=1, bit0=1\n");
printf("  ████████ (8) + (0) + ██ (2) + █ (1) = 11 ✓\n\n");

printf("[0101]: bit3=0, bit2=1, bit1=0, bit0=1\n");
printf("  (0) + ████ (4) + (0) + █ (1) = 5 ✓\n");

return 0;

}