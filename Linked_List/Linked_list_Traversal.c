#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
void linkedTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
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
    second->data = 7890;
    second->next = third;
    
    //Linked third and fourth list
    third->data = 7789547;
    third->next = fourth;
    
    //Terminate the list at the third end
    fourth->data = 66;
    fourth->next = NULL;
    linkedTraversal(head);

    return 0;
}
