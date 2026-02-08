#include <stdio.h>
#include <stdbool.h>

bool isPowerOfTwo(int n) {
    if (n == 1) return true;   // 2^0 = 1
    if (n <= 0 || n % 2 != 0) return false; // negative or odd numbers can't be powers of 2
    return isPowerOfTwo(n / 2);
}

int main() {
    int n;
    scanf("%d", &n);

    if (isPowerOfTwo(n))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
