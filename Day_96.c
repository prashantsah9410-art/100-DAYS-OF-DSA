#include <stdio.h>
#include <stdlib.h>

long long merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    long long inv = 0;

    while(i <= mid && j <= right) {
        if(arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv += (mid - i + 1);
        }
    }

    while(i <= mid) temp[k++] = arr[i++];
    while(j <= right) temp[k++] = arr[j++];

    for(int x = left; x <= right; x++) {
        arr[x] = temp[x];
    }

    return inv;
}

long long mergeSort(int arr[], int temp[], int left, int right) {
    long long inv = 0;
    if(left < right) {
        int mid = (left + right) / 2;
        inv += mergeSort(arr, temp, left, mid);
        inv += mergeSort(arr, temp, mid + 1, right);
        inv += merge(arr, temp, left, mid, right);
    }
    return inv;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n], temp[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    long long inversions = mergeSort(arr, temp, 0, n - 1);

    printf("%lld", inversions);

    return 0;
}