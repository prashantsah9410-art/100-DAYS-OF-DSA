#include <stdio.h>

int isPossible(int arr[], int n, int m, int maxPages) {
    int students = 1, sum = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] > maxPages) return 0;

        if(sum + arr[i] > maxPages) {
            students++;
            sum = arr[i];
            if(students > m) return 0;
        } else {
            sum += arr[i];
        }
    }
    return 1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int left = 0, right = 0, ans = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] > left) left = arr[i];
        right += arr[i];
    }

    while(left <= right) {
        int mid = (left + right) / 2;

        if(isPossible(arr, n, m, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    printf("%d", ans);

    return 0;
}