#include <stdio.h>

int maxProfit(int* prices, int pricesSize) {
    int minPrice = prices[0];
    int max_profit = 0;

    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        } else {
            int profit = prices[i] - minPrice;
            if (profit > max_profit) {
                max_profit = profit;
            }
        }
    }

    return max_profit;
}

int main() {
    int prices[] = {7, 1, 5, 3, 6, 4};
    int n = sizeof(prices) / sizeof(prices[0]);

    int result = maxProfit(prices, n);
    printf("%d\n", result);

    return 0;
}
