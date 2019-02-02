#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		next = nullptr;
	}
};

// Floyd cycle finding Algorithm
bool detectloop(Node *head)
{
	if(head == nullptr)
		return false;
   
   Node *slow,*fast;
   slow = fast = head;
   while(fast != nullptr && fast->next != nullptr)
   {
		fast = fast->next->next;
		slow = slow->next;
		if(fast == slow)
			return true;
   }
   return false;
}