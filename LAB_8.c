#include <stdio.h>

// This function recursively finds all subsets of `w[]`
// that sum to the target value `d`
void subsetSum(int w[], int x[], int k, int n, int curr_sum, int remaining, int d, int *count) {
    x[k] = 1;  // We choose to include w[k] in the current subset

    // Check if current sum + w[k] exactly matches the required sum
    if (curr_sum + w[k] == d) {
        (*count)++;  // A valid subset found
        printf("\nSubset %d: ", *count);
        for (int i = 0; i <= k; i++) {
            if (x[i] == 1)  // print only included elements
                printf("%d ", w[i]);
        }
        printf("\n");
    } 
    // If we can go deeper and still remain within the target sum, explore including the next element
    else if (k + 1 < n && curr_sum + w[k] + w[k + 1] <= d) {
        subsetSum(w, x, k + 1, n, curr_sum + w[k], remaining - w[k], d, count);
    }

    // Now explore the possibility of excluding w[k]
    // We only do this if there's a chance the remaining elements can still form a valid subset
    if (k + 1 < n && curr_sum + remaining - w[k] >= d && curr_sum + w[k] <= d) {
        x[k] = 0;  // Backtrack: mark w[k] as not included
        subsetSum(w, x, k + 1, n, curr_sum, remaining - w[k], d, count);
    }
}

int main() {
    int n, d, sum = 0;
    
    // Step 1: Read total number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int w[n];  // w[] stores the actual input elements (weights)
    int x[n];  // x[] is a helper array to track whether each element is included (1) or not (0)

    // Step 2: Input the elements in ascending order (as required by pruning logic)
    printf("Enter the elements in ascending order:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
        sum += w[i];  // Calculate total sum to help prune unnecessary calls
    }

    // Step 3: Input the desired target sum
    printf("Enter the target sum: ");
    scanf("%d", &d);

    // Step 4: Check if it's even possible to form the sum
    if (sum < d) {
        printf("No solution: total sum less than required.\n");
        return 0;
    }

    int count = 0;  // This keeps track of how many subsets were found
    // Start recursion from index 0, current sum = 0, remaining sum = total sum
    subsetSum(w, x, 0, n, 0, sum, d, &count);

    if (count == 0)
        printf("No solution found.\n");

    return 0;
}
