#include <stdio.h>
#include <stdlib.h>

void heapify(int a[], int n) {
    for (int i = n / 2; i >= 1; i--) {
        int k = i;
        int v = a[k];
        int flag = 0;
        
        while (!flag && 2 * k <= n) {
            int j = 2 * k;
            if (j < n && a[j] < a[j + 1])
                j = j + 1;
            if (v >= a[j])
                flag = 1;
            else {
                a[k] = a[j];
                k = j;
            }
        }
        a[k] = v;
    }
}

void extractMax(int a[], int *n) {
    if (*n >= 1) {
        printf("\nElement deleted is %d\n", a[1]);
        a[1] = a[*n];
        (*n)--;
        heapify(a, *n);
        if (*n != 0) {
            printf("Elements after reconstructing heap\n");
            for (int i = 1; i <= *n; i++)
                printf("%d\t", a[i]);
            printf("\n");
        }
    } else {
        printf("\nNo element to delete\n");
    }
}

int main() {
    int n, ch;
    int a[100]; // Increased size for more flexibility
    for (;;) {
        printf("\n1. Create Heap\n");
        printf("2. Extract Max\n");
        printf("3. Exit\n");
        printf("Read Choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Read number of elements: ");
                scanf("%d", &n);
                printf("Read Elements\n");
                for (int i = 1; i <= n; i++)
                    scanf("%d", &a[i]);
                heapify(a, n);
                printf("Elements after heap:\n");
                for (int i = 1; i <= n; i++)
                    printf("%d\t", a[i]);
                printf("\n");
                break;
            case 2:
                extractMax(a, &n);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
