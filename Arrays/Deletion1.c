#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
//Case 1
struct Node *DeletionAtFirst(struct Node *head, int index)
{
    
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

//Case 2
struct Node *DeletionInBetween(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

//Case 3
struct Node *DeletionAtEnd(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;
    //for(int i = 0; i < index - 1; i++)
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

//Case 4
struct Node *DeleteAvalue(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == value);
    {
        p->next = q->next;
        free(q);
    }
    
    return head;
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    //Linked first and second list
    head->data = 7;
    head->next = second;

    //Linked second and list list
    second->data = 70;
    second->next = third;

    //Linked third and fourth list
    third->data = 700;
    third->next = fourth;

    //Terminate the list at the third end
    fourth->data = 7000;
    fourth->next = NULL;
    printf("\nLinked list before Deletion\n");
    linkedListTraversal(head);

    //head = DeletionAtFirst(head, 1);
    //head = DeletionInBetween(head, 0);
    //head = DeletionAtEnd(head);
    //head = DeleteAvalue(head, 70);
    printf("\nLinked list after Deletion\n");
    linkedListTraversal(head);

    return 0;
}
