#include <stdio.h>

int recBinarySearch(int a[], int left, int right, int val, int *itr) {
    (*itr)++;  
    if (left <= right) {
        int mid = (left + right) / 2;
        if (a[mid] == val)
            return mid;
        if (a[mid] > val) {
            return recBinarySearch(a, left, mid - 1, val, itr);
        }
        return recBinarySearch(a, mid + 1, right, val, itr);
    }
    return -1;
}

int BinarySearch(int arr[], int size, int target, int *itr) {
    *itr = 0; 
    int low = 0;
    int high = size - 1;
    int mid;

    while (low <= high) {
        (*itr)++; 
        mid = (low + high) / 2;

        if (arr[mid] == target) {
            return mid; 
        } else if (target < arr[mid]) {
            high = mid - 1; 
        } else {
            low = mid + 1; 
        }
    }
    return -1; 
}

void sort(int arr[], int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Sorted elements:\n");
    for (i = 0; i < size; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");
}

int main() {
    int i, itr = 0, size;
    printf("Enter size: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter elements:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, size);
    int target;
    printf("Enter element to search: ");
    scanf("%d", &target);
    int f = BinarySearch(arr, size, target, &itr);
    if (f == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at %d location & number of iterations are %d\n", f + 1, itr);
    }
    return 0;
}

