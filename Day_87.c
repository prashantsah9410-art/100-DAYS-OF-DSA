#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int x;
    scanf("%d", &x);

    int left = 0, right = n - 1, found = -1;

    while(left <= right) {
        int mid = (left + right) / 2;
        if(arr[mid] == x) {
            found = mid;
            break;
        } else if(arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    printf("%d", found);

    return 0;
}