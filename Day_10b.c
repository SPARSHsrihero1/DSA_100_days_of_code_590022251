#include <stdio.h>
#include <stdlib.h>

// Function to compare integers for qsort
int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n1, n2;
    scanf("%d", &n1);
    int nums1[n1];
    for (int i = 0; i < n1; i++) scanf("%d", &nums1[i]);

    scanf("%d", &n2);
    int nums2[n2];
    for (int i = 0; i < n2; i++) scanf("%d", &nums2[i]);

    // Sort both arrays
    qsort(nums1, n1, sizeof(int), cmp);
    qsort(nums2, n2, sizeof(int), cmp);

    int i = 0, j = 0;
    int result[n1 < n2 ? n1 : n2]; // max possible size
    int k = 0;

    // Two-pointer intersection
    while (i < n1 && j < n2) {
        if (nums1[i] == nums2[j]) {
            result[k++] = nums1[i];
            i++;
            j++;
        } else if (nums1[i] < nums2[j]) {
            i++;
        } else {
            j++;
        }
    }

    // Print result
    for (int x = 0; x < k; x++) {
        printf("%d ", result[x]);
    }
    printf("\n");

    return 0;
}
