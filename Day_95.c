#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    float value;
    struct Node* next;
} Node;

void insertSorted(Node** head, float value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    if (*head == NULL || (*head)->value >= value) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* current = *head;
    while (current->next != NULL && current->next->value < value) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    Node* buckets[n];
    for (int i = 0; i < n; i++) {
        buckets[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        int index = (int)(arr[i] * n);
        insertSorted(&buckets[index], arr[i]);
    }

    int k = 0;
    for (int i = 0; i < n; i++) {
        Node* current = buckets[i];
        while (current != NULL) {
            arr[k++] = current->value;
            current = current->next;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%.6f", arr[i]);
        if (i != n - 1) printf(" ");
    }

    return 0;
}