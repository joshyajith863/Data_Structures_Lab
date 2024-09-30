#include <stdio.h>

void main() {
    int n, temp, min, i, j, ar[20], count = 0, space = 1;

    // Space complexity calculation
    space = 6 * sizeof(int);  // To account for `n`, `temp`, `min`, `i`, `j`, and `count`
    space += 20 * sizeof(int); // To account for the array `ar` of size 20

    // Input array size
    printf("Enter the limit n (max 20): ");
    scanf("%d", &n);
    count+=2;

    if (n > 20) {
        printf("Error: Limit exceeded. The maximum allowed is 20.\n");
        count+=2;
        return;
    }

    // Input array elements
    printf("Enter the array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &ar[i]);
        count++;
    }
    count++;

    // Selection sort
    for (i = 0; i < n - 1; i++) {
        count++;
        min = i;
        for (j = i + 1; j < n; j++) {
            count++;
            if (ar[j] < ar[min]) {
                min = j;
                count++;
            }
        }
        temp = ar[min];
        ar[min] = ar[i];
        ar[i] = temp;
        count+=3;
    }

    // Output sorted array
    printf("The sorted array is:\n");
    count++;
    for (i = 0; i < n; i++) {
        printf("%d, ", ar[i]);
        count++;
    }
    printf("\n");
    count++;

    // Output time and space complexity
    count+=2;
    printf("The time complexity is estimated as: %d\n", count);
   
    printf("The space complexity is: %d bytes\n", space);
}

