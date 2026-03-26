#include<stdio.h>

int main() {
    
    unsigned int x = 0x8765421;

    //A: least significant byte
    unsigned int A = x & 0xFF;

    //B: LSB same,rest complement
    unsigned int B = (~x & ~0xFF) | (x & 0xFF);

    //C: LSB all in 1
    unsigned int C = x | 0xFF;

    printf("x = 0x%x\n",x);
    printf("A = 0x%x\n",A);
    printf("B = 0x%x\n",B);
    printf("C = 0x%x\n",C);

    return 0;
    

}

/*
சூப்பர் 🔥 இது தான் core confusion — நீ சரியான இடத்துல doubt கேட்டிருக்கிறாய் 👇

🧠 🔥 KEY POINT

👉 நீ சொல்வது சரி:

0xFF = 11111111

👉 ஆனா முக்கியம்:

x = 0x87654321 → இது 4 bytes (32 bits)
⚙️ FULL BINARY VIEW
x = 0x87654321

= 10000111 01100101 01000011 00100001
   (87)     (65)     (43)     (21)

👉 mask:

0xFF = 00000000 00000000 00000000 11111111
🔥 APPLY AND (&)
   10000111 01100101 01000011 00100001   (x)
&  00000000 00000000 00000000 11111111   (mask)
------------------------------------------------
   00000000 00000000 00000000 00100001
💥 RESULT
00100001 = 0x21

👉 full 32-bit form:

0x00000021
🧠 WHY zeros வந்தது?

👉 AND rule:

0 & anything = 0
1 & x = x

👉 first 3 bytes:

mask = 00000000 → result = 0

👉 last byte:

mask = 11111111 → keep original
⚡ BYTE-BY-BYTE VIEW
byte (x)	mask	result
87	00	00 ❌
65	00	00 ❌
43	00	00 ❌
21	FF	21 ✅
🔥 WHY 0x00000021 (not just 0x21)?

👉 because:

variable = 32-bit (4 bytes)

👉 so:

result also 32-bit

👉 internally:

00000000 00000000 00000000 00100001

👉 short form:

0x21

👉 full form:

0x00000021
💣 SUPER IMPORTANT
mask size = full word size

👉 even though:

0xFF = 8 bits

👉 compiler treats as:

00000000 00000000 00000000 11111111
🔥 FINAL INTUITION
0xFF → last byte மட்டும் open
rest → closed (0)
💥 FINAL ONE-LINE
"0xFF AND பண்ணினா → last 8 bits மட்டும் survive, மற்ற எல்லாம் 0 ஆகும்"
*/

//=====xசரி புரிகிறது நான் கொடுத்ததை இது எப்படி கடைசிக்கு மட்டும் எடுத்துக் கொள்ளும் `0xFF = 00000000 00000000 00000000 11111111`0xFF இப்படி போட்டாலே போதுமா மின்னாலில் இருப்பதெல்லாம் 00 எடுத்துவிட்டு கடைசிக்கு மட்டும் ஒன்றை ஆகும் என்று அது புரிந்து கொள்ளுமாx=====x=========x===========x========x======

/*
சூப்பர் 🔥 நீ இப்போ மிக முக்கியமான doubt கேட்டிருக்கிறாய் — இதுதான் type + representation concept 👇

🧠 🔥 SHORT ANSWER
ஆமாம் ✅ 0xFF மட்டும் போட்டாலே போதும்

👉 compiler தான் internally அதை:

00000000 00000000 00000000 11111111

ஆக மாற்றும்

🧠 🔥 எப்படி அது possible?

👉 காரணம்:

C-ல் number size → context (datatype) decide பண்ணும்
⚙️ STEP 1 — literal 0xFF
0xFF

👉 இது:

255 (decimal)

👉 binary:

11111111   (8 bits)
⚙️ STEP 2 — x என்ன type?
unsigned int x = 0x87654321;

👉 unsigned int = 32 bits

🔥 STEP 3 — implicit expansion

👉 compiler செய்கிறது:

0xFF → 0x000000FF

👉 why?

operation செய்ய இரண்டுமே same size ஆகணும்
⚡ RULE
small value → பெரிய datatype-க்கு automatically expand ஆகும்
🔥 APPLY
x & 0xFF

👉 internally:

x        = 87654321
mask     = 000000FF
💥 RESULT
00000021
🧠 முக்கிய insight

👉 நீ manually எழுத வேண்டியது இல்லை:

00000000 00000000 00000000 11111111 ❌

👉 simply:

0xFF ✅
⚙️ ஏன் இப்படிச் design பண்ணியிருக்காங்க?

👉 convenience:

programmer easyஆ எழுதணும்

👉 imagine:

x & 0x00000000000000FF ❌ (very long)
x & 0xFF ✅ (clean)
💣 IMPORTANT NOTE

👉 இது வேலை செய்கிறது because:

0xFF → positive number

👉 but:

~0xFF

👉 becomes:

FFFFFF00 (32-bit)
🔥 INTUITION
0xFF = "last 8 bits ON"

👉 rest automatically:

OFF (0)
⚡ VISUAL
mask:   000000FF
meaning: last byte மட்டும் open
💥 FINAL ONE-LINE
"0xFF மட்டும் போட்டாலே போதும் — compiler அதை full-size mask ஆக expand பண்ணும்"
*/