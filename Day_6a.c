#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    if (n == 0) return 0;

    int j = 0;  // index for unique elements

    for (int i = 1; i < n; i++) {
        if (a[i] != a[j]) {
            j++;
            a[j] = a[i];
        }
    }

    // print unique elements
    for (int i = 0; i <= j; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}