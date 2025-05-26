#include <stdio.h>
// 
int max(int a, int b) {
    return (a > b) ? a
      : b;
}

int knapsack(int W, int weights[], int values[], int n) {
    int dp[n+1][W+1];  // dp[i][w] will hold the max profit for i items and capacity w

    // Build table dp[][] in bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;  // Base case: 0 items or 0 capacity
            else if (weights[i-1] <= w)
                dp[i][w] = max(
                    values[i-1] + dp[i-1][w - weights[i-1]],  // include the item
                    dp[i-1][w]                                // exclude the item
                );
            else
                dp[i][w] = dp[i-1][w];  // item too heavy, exclude
        }
    }

    // Print DP table (optional for understanding)
    printf("\nDP Table:\n");
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            printf("%3d ", dp[i][w]);
        }
        printf("\n");
    }

    return dp[n][W];  // maximum profit
}

int main() {
    int W, n;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the maximum capacity of knapsack: ");
    scanf("%d", &W);

    int weights[n], values[n];

    printf("Enter profit and weight for each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d - Profit and Weight: ", i+1);
        scanf("%d %d", &values[i], &weights[i]);
    }

    int result = knapsack(W, weights, values, n);
    printf("\nMaximum profit = %d\n", result);

    return 0;
}
