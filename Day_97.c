#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Interval;

int compareStart(const void *a, const void *b) {
    return ((Interval*)a)->start - ((Interval*)b)->start;
}

typedef struct {
    int *arr;
    int size;
} MinHeap;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(MinHeap *h, int i) {
    while(i > 0) {
        int p = (i - 1) / 2;
        if(h->arr[p] > h->arr[i]) {
            swap(&h->arr[p], &h->arr[i]);
            i = p;
        } else break;
    }
}

void heapifyDown(MinHeap *h, int i) {
    while(1) {
        int l = 2*i + 1, r = 2*i + 2, smallest = i;
        if(l < h->size && h->arr[l] < h->arr[smallest]) smallest = l;
        if(r < h->size && h->arr[r] < h->arr[smallest]) smallest = r;
        if(smallest != i) {
            swap(&h->arr[i], &h->arr[smallest]);
            i = smallest;
        } else break;
    }
}

void push(MinHeap *h, int val) {
    h->arr[h->size] = val;
    heapifyUp(h, h->size);
    h->size++;
}

void pop(MinHeap *h) {
    h->arr[0] = h->arr[h->size - 1];
    h->size--;
    heapifyDown(h, 0);
}

int top(MinHeap *h) {
    return h->arr[0];
}

int main() {
    int n;
    scanf("%d", &n);

    Interval arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    qsort(arr, n, sizeof(Interval), compareStart);

    MinHeap h;
    h.arr = (int*)malloc(n * sizeof(int));
    h.size = 0;

    push(&h, arr[0].end);

    for(int i = 1; i < n; i++) {
        if(h.size > 0 && arr[i].start >= top(&h)) {
            pop(&h);
        }
        push(&h, arr[i].end);
    }

    printf("%d", h.size);

    free(h.arr);
    return 0;
}