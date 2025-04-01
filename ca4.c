#include <stdio.h>

void swap(int *n1, int *n2) {
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

int Partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low, j = high;
    
    while (i < j) {
        while (arr[i] <= pivot) 
            i++;
        while (arr[j] > pivot) 
            j--;
        
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void QuickSort(int arr[], int low, int high) {
    if (low < high) {
        int loc = Partition(arr, low, high);
        QuickSort(arr, low, loc - 1);
        QuickSort(arr, loc + 1, high);
    }
}

int main() {
    int i, size;
    printf("Enter size: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter elements:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    QuickSort(arr, 0, size - 1);
    
    printf("After sorting: ");
    for (i = 0; i < size; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");
    
    return 0; 
}
