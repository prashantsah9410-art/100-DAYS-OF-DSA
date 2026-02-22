// Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.

// Input:
// - First line: integer n
// - Second line: n space-separated integers (the array)
// - Third line: integer pos (1-based position)
// - Fourth line: integer x (element to insert)

// Output:
// - Print the updated array (n+1 integers) in a single line, space-separated

// Example:
// Input:
// 5
// 1 2 4 5 6
// 3
// 3

// Output:
// 1 2 3 4 5 6

// Explanation: Insert 3 at position 3, elements [4,5,6] shift right
#include <stdio.h>

int main() {
    int n, a, x;
    scanf("%d", &n);

    int array[n + 1];

    // input array (0-based)
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    scanf("%d", &a);  // position (1-based)
    scanf("%d", &x);  // value to insert

    // shift right
    for (int i = n; i >= a; i--) {
        array[i] = array[i - 1];
    }

    // insert
    array[a - 1] = x;

    // print n+1 elements
    for (int i = 0; i <= n; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}