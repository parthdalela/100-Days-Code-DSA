/*Problem: For each element, count how many smaller elements appear on right side.
Use merge sort technique or Fenwick Tree (BIT).*/
#include <stdio.h>
#define MAX_SIZE 100
void merge(int arr[], int temp[], int left, int mid, int right, int count[]) {
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            count[arr[i]] += (right - j + 1);
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}
void mergeSort(int arr[], int temp[], int left, int right, int count[]) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, temp, left, mid, count);
        mergeSort(arr, temp, mid + 1, right, count);
        merge(arr, temp, left, mid, right, count);
    }
}
int main() {
    int n;
    int arr[MAX_SIZE], temp[MAX_SIZE], count[MAX_SIZE] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    mergeSort(arr, temp, 0, n - 1, count);
    for (int i = 0; i < n; i++) {
        printf("%d ", count[arr[i]]);
    }
    return 0;
}
