#include <stdio.h>

void productExceptSelf(int nums[], int n, int result[]) {
    int prefix[n];
    int suffix[n];
    
    // Build prefix products
    prefix[0] = 1;
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] * nums[i - 1];
    }
    
    // Build suffix products
    suffix[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        suffix[i] = suffix[i + 1] * nums[i + 1];
    }
    
    // Build result by multiplying prefix and suffix
    for (int i = 0; i < n; i++) {
        result[i] = prefix[i] * suffix[i];
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    
    int result[n];
    productExceptSelf(nums, n, result);
    
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    
    return 0;
}
