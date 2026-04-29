#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* create(int n)
{
    struct node *head=NULL, *temp, *newnode;
    int i, x;

    for(i=0;i<n;i++)
    {
        scanf("%d",&x);

        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = x;
        newnode->next = NULL;

        if(head==NULL)
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

struct node* deleteKey(struct node *head, int key)
{
    struct node *temp = head, *prev = NULL;

    if(head!=NULL && head->data == key)
    {
        head = head->next;
        free(temp);
        return head;
    }

    while(temp!=NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp==NULL)
        return head;

    prev->next = temp->next;
    free(temp);

    return head;
}

void display(struct node *head)
{
    while(head!=NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main()
{
    int n,key;
    struct node *head;

    scanf("%d",&n);
    head = create(n);

    scanf("%d",&key);

    head = deleteKey(head,key);

    display(head);

    return 0;
}