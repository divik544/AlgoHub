// Merging two sorted linked lists in O(1) space
#include <bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *next;
	node(int data)
	{
		this->data = data;
		next = NULL;
	}
};
void printList(node *head)
{
	while(head)
	{
		cout << (head->data) << ' ';
		head = head->next;
	}
	cout << endl;
}

// merges two sorted list into one big list
node* mergeList(node* a, node* b)
{
	if(b == NULL)
		return a;
	node* head = NULL;
	if(a->data < b->data)
	{
		head = new node(a->data);
		a = a->next;
	}
	else
	{
		head = new node(b->data);
		b = b->next;
	}
	node* end = head;
	while(a!= NULL && b!= NULL)
	{
		if(a->data < b->data)
		{
			end->next = a;
			a = a->next;
			end->next->next = NULL;
		}
		else
		{
			end->next = b;
			b = b->next;
			end->next->next = NULL;
		}
		end = end->next;
	}
	if(a!=NULL)
		end->next = a;
	if(b!=NULL)
		end->next = b;
	return head;
}
int main()
{
	node *root = new node(1);
	root->next = new node(3);
	root->next->next = new node(5);
	node *head = new node(2);
	head->next = new node(4);
	head->next->next = new node(6);
	printList(mergeList(root,head));
	// 1 2 3 4 5 6	
}