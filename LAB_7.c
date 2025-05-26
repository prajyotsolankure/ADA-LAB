#include <stdio.h>

// Arrays to store weights and profits of items
int w[10], p[10], n;

// Function to return the maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Recursive knapsack function
int knap(int i, int m) {
    // Base case: if at the last item
    if (i == n) {
        return (w[i] > m) ? 0 : p[i];
    }

    // If current item's weight exceeds capacity, skip it
    if (w[i] > m) {
        return knap(i + 1, m);
    }

    // Otherwise, return max of:
    // - excluding the item
    // - including the item (reduce capacity and add profit)
    return max(knap(i + 1, m), knap(i + 1, m - w[i]) + p[i]); // ✅ Fixed this line
}

int main() {
    int m;
    printf("Enter the capacity: ");
    scanf("%d", &m);

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter profit followed by weight:\n");
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &p[i], &w[i]);
    }

    int max_profit = knap(1, m);
    printf("Max profit: %d\n", max_profit);

    return 0;
}
