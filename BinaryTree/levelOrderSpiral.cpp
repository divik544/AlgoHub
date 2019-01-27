#include <iostream>
#include <stack>
using namespace std;
struct tnode
{
	int data;
	tnode *left;
	tnode *right;
	tnode(int data)
	{
		this->data = data;
		left = right = nullptr;
	}
};
void levelOrderSpiral(tnode *root)
{
	stack< pair<tnode*,int> > ostk,estk;
	ostk.push({root,1});
	pair<tnode*,int> temp;
	while(!ostk.empty() || !estk.empty())
	{
		while(!ostk.empty())
		{
			temp = ostk.top();
			ostk.pop();
			if(temp.first == nullptr)
				continue;
			cout << (temp.first->data) << ' ';
			estk.push({temp.first->right,temp.second+1});
			estk.push({temp.first->left,temp.second+1});
		}
		while(!estk.empty())
		{
			temp = estk.top();
			estk.pop();
			if(temp.first == nullptr)
				continue;
			cout << (temp.first->data) << ' ';
			ostk.push({temp.first->left,temp.second+1});
			ostk.push({temp.first->right,temp.second+1});
		}
	}
	cout << endl;
}
int main()
{
	tnode *root = new tnode(1); 
	root->left        = new tnode(2); 
	root->right       = new tnode(3); 
	root->left->left  = new tnode(7); 
	root->left->right = new tnode(6); 
	root->right->left  = new tnode(5); 
	root->right->right = new tnode(4); 
	levelOrderSpiral(root);	// Expected Output : 1 2 3 4 5 6 7
}