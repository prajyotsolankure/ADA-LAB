#include <stdio.h>

#define MAX 10

int set[MAX];            // Array to hold the input set (assumed to be in increasing order)
int include[MAX];        // Array to keep track of elements included in the current subset
int targetSum;           // Target sum to find subsets for

// Recursive function to find subsets with the required sum
void findSubsets(int currentSum, int index, int remainingSum) {
    int i;

    include[index] = 1;  // Include current element in subset

    // If current sum + set[index] equals the target, print the subset
    if ((currentSum + set[index]) == targetSum) {
        for (i = 1; i <= index; i++) {
            if (include[i] == 1)
                printf("%d ", set[i]);
        }
        printf("\n");
    }

    // If including next element does not exceed target, continue recursion
    else if (currentSum + set[index] + set[index + 1] <= targetSum) {
        findSubsets(currentSum + set[index], index + 1, remainingSum - set[index]);
    }

    // If it's still possible to find a valid subset, try without current element
    if ((currentSum + remainingSum - set[index] >= targetSum) && 
        (currentSum + set[index + 1] <= targetSum)) {
        include[index] = 0;  // Exclude current element
        findSubsets(currentSum, index + 1, remainingSum - set[index]);
    }
}

int main() {
    int i, n, totalSum = 0;

    printf("\nEnter the number of elements in the set: ");
    scanf("%d", &n);

    printf("\nEnter the elements in increasing order: ");
    for (i = 1; i <= n; i++) {
        scanf("%d", &set[i]);
    }

    printf("\nEnter the target subset sum: ");
    scanf("%d", &targetSum);

    // Calculate total sum of the input set
    for (i = 1; i <= n; i++) {
        totalSum += set[i];
    }

    // Check if it's even possible to form a subset with the target sum
    if (totalSum < targetSum || set[1] > targetSum) {
        printf("\nNo subset possible");
    } else {
        findSubsets(0, 1, totalSum);
    }

    return 0;
}
