// Problem: Given an array of integers, find two elements whose sum is closest to zero.

// Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the pair of elements whose sum is closest to zero

// Example:
// Input:
// 5
// 1 60 -10 70 -80

// Output:
// -10 1

// Explanation: Among all possible pairs, the sum of -10 and 1 is -9, which is the closest to zero compared to other pairs.

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    // Input size
    scanf("%d", &n);

    int arr[n];

    // Input array
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int min_sum = 1000000;
    int num1 = 0, num2 = 0;

    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {

            int sum = arr[i] + arr[j];

            if(abs(sum) < abs(min_sum)) {
                min_sum = sum;
                num1 = arr[i];
                num2 = arr[j];
            }
        }
    }

    printf("%d %d", num1, num2);

    return 0;
}