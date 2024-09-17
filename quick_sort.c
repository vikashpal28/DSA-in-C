#include <stdio.h>
int split(int a[], int l, int u) {
     int t;
    int piv = a[l];
    int i = l+1;
    int j = u;
    while(j>=i){
        while(a[i]<piv){
            i = i+1;
        }
        while(a[j]>piv){
            j = j-1;
        }
        if(j>i){
             t = a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    t = a[j];
    a[j]=a[l];
    a[l]=t;
    return j;

}

void quicksort(int a[], int l, int u) {
    if (l < u) {
        int pos = split(a, l, u);
        quicksort(a, l, pos - 1);
        quicksort(a, pos + 1, u);
    }
}

int main() {
    int a[10];
    int l = 0; // Initialize l and u
    int u = 9;

    printf("Enter 10 numbers:\n ");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
    }

    quicksort(a, l, u);

    printf("Sorted array:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
/*
output
Enter 10 numbers:
 1
90
87
45
32
23
43
12
19
10
Sorted array:
1 10 12 19 23 32 43 45 87 90*/