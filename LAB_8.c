#include <stdio.h>

#define MAX 10

int set[MAX];
int subset[MAX];
int n, target;

void findSubsets(int index, int currentSum, int subsetSize) {
    // If currentSum matches target, print the subset
    if (currentSum == target) {
        printf("Subset found: ");
        for (int i = 0; i < subsetSize; i++)
            printf("%d ", subset[i]);
        printf("\n");
        return;
    }

    // If index is out of range or sum exceeded, stop
    if (index >= n || currentSum > target)
        return;

    // Include current element
    subset[subsetSize] = set[index];
    findSubsets(index + 1, currentSum + set[index], subsetSize + 1);

    // Exclude current element
    findSubsets(index + 1, currentSum, subsetSize);
}

int main() {
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &set[i]);

    printf("Enter target sum: ");
    scanf("%d", &target);

    printf("Subsets with sum %d:\n", target);
    findSubsets(0, 0, 0);

    return 0;
}
