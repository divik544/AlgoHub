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
void removeLoop(Node *root)
{
	if(root == NULL)
	return;
	Node *slow,*fast;
	slow = fast = root;
	bool found = false;
	while(fast&&fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast)
		{
			found = true;
			break;
		}
	}
	if(!found) return;
	slow = root;
	Node *prev = fast;
	while(slow != fast)
	{
		prev = fast;
		slow = slow->next;
		fast = fast->next;
	}
	prev->next = NULL;
	return;
}
