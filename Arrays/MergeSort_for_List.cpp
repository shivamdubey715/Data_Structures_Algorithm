// C++ code for linked list merged sort
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class Node {
public:
	int data;
	Node* next;
};

/* function prototypes */
Node* SortedMerge(Node* a, Node* b);
void FrontBackSplit(Node* source,
					Node** frontRef, Node** backRef);

/* sorts the linked list by changing next pointers (not data) */
void MergeSort(Node** headRef)
{
	Node* head = *headRef;
	Node* a;
	Node* b;

	/* Base case -- length 0 or 1 */
	if ((head == NULL) || (head->next == NULL)) {
		return;
	}

	/* Split head into 'a' and 'b' sublists */
	FrontBackSplit(head, &a, &b);

	/* Recursively sort the sublists */
	MergeSort(&a);
	MergeSort(&b);

	/* answer = merge the two sorted lists together */
	*headRef = SortedMerge(a, b);
}

/* See https:// www.geeksforgeeks.org/?p=3622 for details of this
function */
Node* SortedMerge(Node* a, Node* b)
{
	Node* result = NULL;

	/* Base cases */
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);

	/* Pick either a or b, and recur */
	if (a->data <= b->data) {
		result = a;
		result->next = SortedMerge(a->next, b);
	}
	else {
		result = b;
		result->next = SortedMerge(a, b->next);
	}
	return (result);
}

/* UTILITY FUNCTIONS */
/* Split the nodes of the given list into front and back halves,
	and return the two lists using the reference parameters.
	If the length is odd, the extra node should go in the front list.
	Uses the fast/slow pointer strategy. */
void FrontBackSplit(Node* source,
					Node** frontRef, Node** backRef)
{
	Node* fast;
	Node* slow;
	slow = source;
	fast = source->next;

	/* Advance 'fast' two nodes, and advance 'slow' one node */
	while (fast != NULL) {
		fast = fast->next;
		if (fast != NULL) {
			slow = slow->next;
			fast = fast->next;
		}
	}

	/* 'slow' is before the midpoint in the list, so split it in two
	at that point. */
	*frontRef = source;
	*backRef = slow->next;
	slow->next = NULL;
}

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
}

/* Function to insert a node at the beginning of the linked list */
void push(Node** head_ref, int new_data)
{
	/* allocate node */
	Node* new_node = new Node();

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}


int main()
{
	/* Start with the empty list */
	Node* res = NULL;
	Node* a = NULL;

	/* Let us create a unsorted linked lists to test the functions
Created lists shall be a: 2->3->20->5->10->15 */
	push(&a, 15);
	push(&a, 10);
	push(&a, 5);
	push(&a, 20);
	push(&a, 3);
	push(&a, 2);

	
	MergeSort(&a);

	cout << "Sorted Linked List is: \n";
	printList(a);
    cout << endl;

	return 0;
}
// Time Complexity: O(n*log n)

// Space Complexity: O(n*log n)


// Method 2:
#include<iostream>
using namespace std;

//Node structure
struct Node{
	int data;
	Node *next;
};

//function to insert in list
void insert(int x,Node **head) {
	if(*head == NULL){
		*head = new Node;
		(*head)->data = x;
		(*head)->next = NULL;
		return;
	}
	Node *temp = new Node;
	temp->data = (*head)->data;
	temp->next = (*head)->next;
	(*head)->data=x;
	(*head)->next=temp;
}

//function to print the list
void print(Node *head) {
	Node *temp=head;
	while(temp!=NULL) {
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}

Node *merge(Node *firstNode,Node *secondNode) {
	Node *merged = new Node;
	Node *temp = new Node;
	
	//merged is equal to temp so in the end we have the top Node.
	merged = temp;

	//while either firstNode or secondNode becomes NULL
	while(firstNode != NULL && secondNode != NULL) {
	
		if(firstNode->data<=secondNode->data) {
			temp->next = firstNode;
			firstNode = firstNode->next;
		}
		
		else {
			temp->next = secondNode;
			secondNode = secondNode->next;
		}
		temp = temp->next;
	}
	
//any remaining Node in firstNode or secondNode gets inserted in the temp List
	while(firstNode!=NULL) {
		temp->next = firstNode;
		firstNode = firstNode->next;
		temp = temp->next;
	}

	while(secondNode!=NULL) {
		temp->next = secondNode;
		secondNode = secondNode->next;
		temp = temp->next;
	}
	//return the head of the sorted list
	return merged->next;
}

//function to calculate the middle Element
Node *middle(Node *head) {
	Node *slow = head;
	Node *fast = head->next;
	
	while(slow->next != NULL && (fast!=NULL && fast->next!=NULL)) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

//function to sort the given list
Node *sort(Node *head){
	
	if(head->next == NULL) {
		return head;
	}

	Node *mid = new Node;
	Node *head2 = new Node;
	mid = middle(head);
	head2 = mid->next;
	mid->next = NULL;
	//recursive call to sort() hence diving our problem, and then merging the solution
	Node *finalhead = merge(sort(head),sort(head2));
	return finalhead;
}
int main(void) {
	Node *head = NULL;
	int n[]={7,10,5,20,3,2};
	for(int i=0;i<6;i++) {
		insert(n[i],&head); //inserting in the list
	}
cout<<"\nSorted Linked List is: \n";
	print(sort(head));	 //printing the sorted list returned by sort()
	return 0;
}


// Time Complexity: O(n*log n)

// Space Complexity: O(log n)