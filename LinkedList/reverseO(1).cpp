// Reversing a linked list in O(1) extra space
#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		next = NULL;
	}
};

// Reversing LL using 3 extra pointers
Node* reverse(Node *head)
{
    if(head == NULL)
        return head;
    Node *temp,*start = head,*end = head->next;
    while(end != NULL)
    {
        temp = end->next;
        end->next = head;
        head = end;
        start->next = temp;
        end = temp;
    }
    return head;
}

/* Reversing LL using 2 extra pointers
Node* reverse(Node *head)
{
    if(head == NULL)
        return head;
    Node *temp,*start = head;
    while(start->next != NULL)
    {
        temp = start->next->next;
        start->next->next = head;
        head = start->next;
        start->next = temp;
    }
    return head;
}*/