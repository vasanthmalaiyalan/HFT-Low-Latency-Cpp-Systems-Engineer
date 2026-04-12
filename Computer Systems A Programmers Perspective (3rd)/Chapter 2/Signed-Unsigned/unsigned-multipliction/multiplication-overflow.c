#include<stdio.h>
#include<limits.h>

// Check if multiplication overflow
int tmult_ok(int x, int y) {

    // Special fast cases
    if (x == 0 || y == 0) 
        return 1;

    int p = x * y;
    
    // main check
    if (p / x != y)
       return 0;

    return 1;   
}

int main() {

    int test[][2] = {
        {10, 20},             // normal
        {INT_MAX, 2},        // positive onverflow
        {INT_MIN, 2},       // negative overflow
        {1000, -3},         // normal negative
        {-20000, -20000},   // overflow
        {0, 9999},          // zero case
        {INT_MIN, -1},      // Special overflow case
    };

    int n = sizeof(test) / sizeof(test[0]);

    printf("======== Signed Multiplication Overflow Check ==============\n\n");

    for (int i = 0; i < n; i++) {

        int x = test[i][0];
        int y = test[i][1];
        int p = x * y;

        printf("x = %d, y = %d\n", x, y);
        printf("x * y = %d\n", p);

        if (tmult_ok(x, y))
           printf("Result: SAFE (No Overflow)\n");
        else 
           printf("Result: (Overflow) \n");
           
        printf("-----------------------------------\n");
    }
    return 0;
}

/*
🔴 Code
int n = sizeof(test) / sizeof(test[0]);
🔹 1. test array என்ன?
int test[][2] = {
    {10, 20},
    {INT_MAX, 2},
    {INT_MIN, 2},
    {1000, -3},
    {-20000, -20000},
    {0, 9999},
    {INT_MIN, -1},
};

👉 இதில்:

7 rows
2 columns
🔹 2. sizeof(test)

👉 total elements:

7 × 2 = 14 ints

👉 1 int = 4 bytes (usually)

👉 so:

sizeof(test) = 14 × 4 = 56 bytes
🔹 3. sizeof(test[0])

👉 first row:

{10, 20} → 2 ints

👉 so:

sizeof(test[0]) = 2 × 4 = 8 bytes
🔥 4. Final calculation
n = 56 / 8 = 7
🔴 உன் doubt: “448 / 7?”

👉 இது incorrect because:

1 int = 4 bytes ❗ (not 32 bits directly)
sizeof returns bytes, not bits
🔹 Wrong thinking
1 int = 32 bits
→ 14 × 32 = 448 ❌ (bits)

👉 but sizeof:

returns bytes → 56 ✅
🔥 5. Correct logic
sizeof(test)      = total bytes
sizeof(test[0])   = one row bytes

👉 so:

number of rows = total / one row
🔹 6. Visual
[ row1 ][ row2 ][ row3 ] ... [ row7 ]
   8B      8B      8B          8B

total = 56B

👉

56 / 8 = 7 rows
*/

//===================================

/*
🔴 Given
x = -2147483648   (INT_MIN)
y = 2
🔹 1. Real math (CPU இல்லாமல்)
-2147483648 × 2 = -4294967296

👉 இது:

int rangeக்கு வெளியே ❌

👉 (range = -2147483648 to 2147483647)

🔴 2. CPU என்ன பண்ணும்?

👉 CPU:

mod 2^32 arithmetic பயன்படுத்தும்

👉 அதாவது:

result = (-4294967296) mod 2^32
🔥 3. Calculation
2^32 = 4294967296

👉

-4294967296 + 4294967296 = 0

👉 so:

result = 0 😳
*/