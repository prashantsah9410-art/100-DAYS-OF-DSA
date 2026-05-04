#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Interval;

int compare(const void *a, const void *b) {
    return ((Interval*)a)->start - ((Interval*)b)->start;
}

int main() {
    int n;
    scanf("%d", &n);

    Interval arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    qsort(arr, n, sizeof(Interval), compare);

    Interval res[n];
    int k = 0;

    res[k++] = arr[0];

    for(int i = 1; i < n; i++) {
        if(arr[i].start <= res[k - 1].end) {
            if(arr[i].end > res[k - 1].end) {
                res[k - 1].end = arr[i].end;
            }
        } else {
            res[k++] = arr[i];
        }
    }

    for(int i = 0; i < k; i++) {
        printf("%d %d", res[i].start, res[i].end);
        if(i != k - 1) printf("\n");
    }

    return 0;
}