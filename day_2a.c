
#include <stdio.h>
void deleteAtPosition(int arr[], int *n, int pos) {
    if (pos < 1 || pos > *n) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = pos - 1; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--; // Decrease the size of the array
}
int main() {
    int n, pos;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the position to delete (1-based index): ");
    scanf("%d", &pos);
    
    deleteAtPosition(arr, &n, pos);
    
    printf("Array after deletion:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}   
