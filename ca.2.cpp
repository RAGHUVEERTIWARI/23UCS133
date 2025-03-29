#include <stdio.h>

void MaxMin(int arr[], int i, int j, int *max, int *min) {
    int max1, min1, mid;
    if (i == j) {
        *max = *min = arr[i];
    } else if (i == j - 1) {
        if (arr[i] < arr[j]) {
            *max = arr[j];
            *min = arr[i];
        } else {
            *max = arr[i];
            *min = arr[j];
        }
    } else {
        mid = (i + j) / 2;
        MaxMin(arr, i, mid, max, min);
        MaxMin(arr, mid + 1, j, &max1, &min1);
        
        if (*max < max1)
            *max = max1;
        if (*min > min1)
            *min = min1;
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
    int min = arr[0];
    int max = arr[0];
    MaxMin(arr, 0, size - 1, &max, &min);
    printf("Maximum element is %d\n", max);
    printf("Minimum element is %d\n", min);
    return 0;
}
