// Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers (first list)
// - Third line: integer m
// - Fourth line: m space-separated integers (second list)

// Output:
// - Print the merged linked list elements, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 4
// 15 25 35 45

// Output:
// 10 15 20 25 30 35 40 45 50

// Explanation:
// Compare nodes of both lists, append smaller to result, continue until all nodes are merged.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* create(int n)
{
    struct node *head = NULL, *temp, *newnode;
    int i, x;

    for(i = 0; i < n; i++)
    {
        scanf("%d", &x);

        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = x;
        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

struct node* merge(struct node *l1, struct node *l2)
{
    struct node *head = NULL, *temp = NULL, *newnode;

    while(l1 != NULL && l2 != NULL)
    {
        newnode = (struct node*)malloc(sizeof(struct node));

        if(l1->data < l2->data)
        {
            newnode->data = l1->data;
            l1 = l1->next;
        }
        else
        {
            newnode->data = l2->data;
            l2 = l2->next;
        }

        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }

    while(l1 != NULL)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = l1->data;
        newnode->next = NULL;
        temp->next = newnode;
        temp = newnode;
        l1 = l1->next;
    }

    while(l2 != NULL)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = l2->data;
        newnode->next = NULL;
        temp->next = newnode;
        temp = newnode;
        l2 = l2->next;
    }

    return head;
}

void display(struct node *head)
{
    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main()
{
    int n, m;
    struct node *list1, *list2, *result;

    scanf("%d", &n);
    list1 = create(n);

    scanf("%d", &m);
    list2 = create(m);

    result = merge(list1, list2);

    display(result);

    return 0;
}