#include <stdio.h>

void main() {,
    int n, i, key, flag = 0, ar[100], count = 0,space =0;
	
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    count += 1; 

    printf("Enter the array elements: ");
    count += 1; 
    for (i = 0; i < n; i++) {
        scanf("%d", &ar[i]);
        count += 1; 
    }
    count += 1; 

    printf("Enter the search element: ");
    scanf("%d", &key);
    count += 2; 

    for (i = 0; i < n; i++) {
        if (ar[i] == key) {
            flag = 1;
            printf("The %d is found at position %d\n", key, i + 1);
            count += 3; 
            break;
        }
        count += 2; 
    }

    if (flag == 0) {
        printf("The %d is not found\n", key);
        count += 2; 
    }

    printf("\nTime Complexity= %d\n", count);
    printf("Space Complexity is (20+(n*4)));

 
}

