#include <stdio.h>
int main() {    
    int p, q;
    printf("Enter number of entries in server log 1: ");
    scanf("%d", &p);
    int log1[p];
    printf("Enter %d sorted integers for server log 1: ", p);
    for (int i = 0; i < p; i++) {
        scanf("%d", &log1[i]);
    }

    printf("Enter number of entries in server log 2: ");
    scanf("%d", &q);
    int log2[q];
    printf("Enter %d sorted integers for server log 2: ", q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &log2[i]);
    }

    // Merge the two logs
    int merged[p + q];
    int i = 0, j = 0, k = 0;
    
    while (i < p && j < q) {
        if (log1[i] < log2[j]) {
            merged[k++] = log1[i++];
        } else {
            merged[k++] = log2[j++];
        }
    }
    
    while (i < p) {
        merged[k++] = log1[i++];
    }
    
    while (j < q) {
        merged[k++] = log2[j++];
    }

    // Print the merged log
    printf("Merged arrival times: ");
    for (int m = 0; m < k; m++) {
        printf("%d ", merged[m]);
    }
    printf("\n");

    return 0;
}