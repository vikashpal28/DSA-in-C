#include <stdio.h>

int main() {
    int a[5], i, j, t, min;

    printf("Enter the values for array 'a':\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < 5 - 1; i++) {
        min = i;
        for (j = i + 1; j < 5; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        t = a[min];
        a[min] = a[i];
        a[i] = t;
    }

    printf("Sorted array:\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
/*
output
Enter the values for array 'a':
0
9
1
2
7
Sorted array:
0 1 2 7 9
*/