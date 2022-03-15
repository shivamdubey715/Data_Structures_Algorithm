#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int data;
    struct ListNode *next;
    ListNode(int x)
    {
        data = x;
        next = NULL;
    }
};

ListNode *rotateRight(ListNode *head, int k)
{
    if (!head || !head->next || k == 0)
    {
        return head;
    }
    ListNode *curr = head;
    int len = 1;
    while (curr->next && ++len)
    {
        curr = curr->next;
    }
    curr->next = head;
    k = k % len;
    k = len - k;
    while (k--)
    {
        curr = curr->next;
    }
    head = head->next;
    curr->next = NULL;
}

int main()
{
    int val, n, k;
    cin >> n;
    cin >> val;
    ListNode *head = new ListNode(val);
    ListNode *tail = head;

    for (int i = 0; i < n - 1; i++)
    {
        cin >> val;
        tail->next = new ListNode(val);
        tail = tail->next;
    }
    cin >> k;
    rotateRight(head, k);
    while (head != NULL)
    {
        cout << head->data << " ";
    }
    cout << endl;
    return 0;
}