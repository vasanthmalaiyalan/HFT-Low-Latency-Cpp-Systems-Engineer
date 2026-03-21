#include<stdio.h>

//print color name
void print_color(int c) {
    switch(c) {
        case 0: printf("Black"); break;
        case 1: printf("Blue"); break;
        case 2: printf("Green"); break;
        case 3: printf("Cyan"); break;
        case 4: printf("Red"); break;
        case 5: printf("Magenta"); break;
        case 6: printf("Yellow"); break;
        case 7: printf("White"); break;
    }
}
int main() {
    int colors[8] = {0,1,2,3,4,5,6,7};

    printf("=== Complement ===\n");
    for (int i = 0; i < 8; i++) {
        int comp = (~colors[i]) & 0x7; // 3 bits mask(111 = 7)
        print_color(colors[i]);
        printf(" -> ");
        print_color(comp);
        printf("\n");
    }

    printf("\n=== Operation ===\n");

    int Blue = 1; //001
    int Green = 2; //010
    int Yellow = 6; //110
    int Cyan = 3; //011
    int Red = 4; //100
    int Magenta = 5; //101

    return 0;

}

//==x========xஇங்கு ~ not யூஸ் பண்ணப்பட்டு இருப்பதால் colors[0] வில் உள்ள 0 என்று வந்தால் அது எப்படி ரியாக்ட் செய்யும்x===========x==========x======

/*
சூப்பர் 🔥 இது தான் ~ (NOT) operator real behavior — நீ கேட்டது ரொம்ப முக்கியம் 👇

🧠 🔥 QUESTION
(~colors[i]) & 0x7

👉 colors[0] = 0 என்றால்:

~0 எப்படி behave ஆகும்?
⚠️ முக்கியம்

👉 ~ operator bit-level flip பண்ணும்
👉 அது 3 bits மட்டும் இல்ல ❌
👉 அது full integer bits (usually 32 bits) மேல் வேலை செய்கிறது

🔥 STEP-BY-STEP
🟢 colors[0] = 0
0 = 00000000 00000000 00000000 00000000   (32-bit)
🔵 apply ~
~0 = 11111111 11111111 11111111 11111111

👉 இது:

-1 (two's complement)
⚡ இப்போ mask apply
(~0) & 0x7
mask:
0x7 = 00000000 00000000 00000000 00000111
AND:
11111111 11111111 11111111 11111111
00000000 00000000 00000000 00000111
------------------------------------
00000000 00000000 00000000 00000111
💥 RESULT
111 = 7 → White
🧠 FINAL MEANING
Black (000) → complement → White (111)
🔥 GENERAL RULE

👉 எந்த color ஆனாலும்:

(~x) & 0x7

👉 steps:

1. ~x → எல்லா bits flip
2. & 0x7 → last 3 bits மட்டும் keep
⚡ EXAMPLE
Blue (001)
001 → ~ → 110 (last 3 bits)
→ Yellow
💣 IMPORTANT INSIGHT
~ alone use பண்ணினா → wrong result ❌
mask (& 0x7) MUST ❗
🔥 WHY mask தேவை?

👉 because:

~ → 32-bit flip
நாம் வேண்டியது → 3-bit RGB மட்டும்
⚡ ANALOGY
~ = முழு room light ON/OFF
mask = spotlight → RGB மட்டும் பார்க்கிறது
💥 FINAL ONE-LINE
"~ operator எல்லா bits flip பண்ணும், & 0x7 மட்டும் RGB 3 bits retain பண்ணும்"
*/

//=======x`(~colors[i]) & 0x7`இதுவே 2 என்று வந்தால் எப்படி ரியாத் செய்யும்x=========x========x=========x=====

/*
சூப்பர் 🔥 இப்போ நீ கேட்குறது:

(~colors[i]) & 0x7

👉 colors[i] = 2 (Green) என்றால் என்ன நடக்கும்?

நாம step-by-step clear பாக்கலாம் 👇

🧠 🔥 STEP 1 — value
2 = 010   (RGB → Green)

👉 full int (32-bit):

00000000 00000000 00000000 00000010
🔥 STEP 2 — apply ~
~2 = 11111111 11111111 11111111 11111101

👉 (எல்லா bits flip)

🔥 STEP 3 — mask apply
(~2) & 0x7
mask:
0x7 = 00000000 00000000 00000000 00000111
AND:
11111111 11111111 11111111 11111101
00000000 00000000 00000000 00000111
------------------------------------
00000000 00000000 00000000 00000101
💥 RESULT
101 = 5 → Magenta
🧠 RGB LEVEL EXPLANATION
Original: 010 (Green)

Flip:
0 → 1
1 → 0
0 → 1

→ 101 (Magenta)
🔥 INTUITION

👉 complement means:

ON → OFF
OFF → ON

👉 Green:

R=0 G=1 B=0

👉 complement:

R=1 G=0 B=1 → Magenta
💣 IMPORTANT

👉 ~ alone:

32-bit flip ❌ (too big)

👉 & 0x7:

only last 3 bits keep ✅
⚡ QUICK SHORTCUT
2 (010) → flip → 101 → 5
💥 FINAL ONE-LINE
"(~2) & 0x7 → 010 flip → 101 → Magenta"
*/