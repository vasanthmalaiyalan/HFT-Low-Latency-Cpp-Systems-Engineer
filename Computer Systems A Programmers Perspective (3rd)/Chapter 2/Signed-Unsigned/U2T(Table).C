#include<stdio.h>
#include<stdint.h>

// 4-bits B2T Manual
int B2T4(unsigned char bits) {
    // MSB Weight = 8
    int msb = (bits >> 3) & 1;
    int rest = bits & 0x7; //lower 3 bits
    return -msb * 8 + rest;
}

int main() {

    printf("Signed Bits    Unsigned   (4 bits=2^4)    U2T Check\n");
    printf("________________________________________________\n");

    for (int x = -8; x <= 7; x++) {
        //T2U
        unsigned char u = (unsigned char) (x & 0xF);
        // U2T
        int back = B2T4(u);

        printf("%4d    [",x);
        for (int i = 3; i >= 0; i-- ) {
            printf("%d", (u >> i) & 1);   
        }
         printf("]    %3u      ", u); 

        if (x < 0) 
            printf("%d+16=%d   ", x, x+16);
        else
            printf("%d (same)  ", x);
        

        if (u > 7) 
            printf("%d-16=%d", u, u-16);
        else
            printf("%d (same)", u);
        
        printf("\n");

    }
    return 0;
}


/*
🔥 Super — இப்ப நீ கேக்குறது real internal flow. Step-by-step clear பண்ணுறேன் 👇

🧠 Given
int x = -8;
unsigned char u = (unsigned char)(x & 0xF);

👉 question:
-8 (32-bit) → எப்படி unsigned (4-bit view) ஆக மாறுது?

🔥 Step 1: x = -8 (32-bit two’s complement)
11111111 11111111 11111111 11111000

👉 இது signed representation ✔️

🔥 Step 2: & 0xF (mask)
0xF = 00000000 00000000 00000000 00001111

👉 apply AND:

11111111 11111111 11111111 11111000
&
00000000 00000000 00000000 00001111
-----------------------------------
00000000 00000000 00000000 00001000

👉 result:

00001000
🧠 Step 3: what just happened?
👉 higher 28 bits → removed ❌
👉 last 4 bits மட்டும் retain ✔️

👉 effectively:

-8 → last 4 bits = 1000
🔥 Step 4: cast to unsigned char
(unsigned char)

👉 இங்கே:

bits change ஆகாது ❌
interpretation மட்டும் change ✔️
🧠 Final interpretation
00001000 = 8

👉 so:

u = 8 ✔️
*/