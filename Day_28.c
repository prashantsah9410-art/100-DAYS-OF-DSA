#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

int main() {
    int n, x, i;
    struct node *head = NULL, *temp = NULL, *newnode = NULL;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &x);
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = x;

        if(head == NULL) {
            head = newnode;
            temp = newnode;
            newnode->next = head;
        } else {
            temp->next = newnode;
            temp = newnode;
            newnode->next = head;
        }
    }

    temp = head;

    if(head != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while(temp != head);
    }

    return 0;
}