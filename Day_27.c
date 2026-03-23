// Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers (first list)
// - Third line: integer m
// - Fourth line: m space-separated integers (second list)

// Output:
// - Print value of intersection node or 'No Intersection'

// Example:
// Input:
// 5
// 10 20 30 40 50
// 4
// 15 25 30 40 50

// Output:
// 30

// Explanation:
// Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* append(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (!head) return newNode;
    struct Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}

int getLength(struct Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

int findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    if (len1 > len2) {
        while (diff--) head1 = head1->next;
    } else {
        while (diff--) head2 = head2->next;
    }

    while (head1 && head2) {
        if (head1->data == head2->data) return head1->data;
        head1 = head1->next;
        head2 = head2->next;
    }

    return -1;
}

int main() {
    int n, m, x;
    struct Node *head1 = NULL, *head2 = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head1 = append(head1, x);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        head2 = append(head2, x);
    }

    int result = findIntersection(head1, head2);

    if (result == -1)
        printf("No Intersection");
    else
        printf("%d", result);

    return 0;
}