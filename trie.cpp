//Tries
//Supports 3 Operations (i) insertion (ii) deletion (iii) count the total words with given prefix
//Status Accepted tested on Contacts(https://www.hackerrank.com/challenges/contacts/problem)
#include<iostream>
#include<unordered_map>
using std::cin;
using std::cout;

struct trienode
{
	std::unordered_map<char, trienode* > child;
	bool end = false;
	int prefix = 0;
};

void insertWord(const std::string& word, trienode* head)
{
	trienode* cur = head;
	int n = word.length();
	for(int i = 0; i < n; i++)
	{
		if(cur->child.find(word[i]) == cur->child.end())
		{
			trienode* t = new trienode;
			cur->child.insert({word[i], t});
		}
		cur->prefix = cur->prefix + 1;
		cur = cur->child.at(word[i]);
	}
	cur->end = true;
}

bool searchWord(const std::string& word, trienode* head)
{
	trienode* cur = head;
	int n = word.length();
	for(int i = 0; i < n; i++)
	{
		if(cur->child.find(word[i]) == cur->child.end())
			return false;
		cur = cur->child.at(word[i]);
	}
	return cur->end;
}

int prefixCount(const std::string& word, trienode* head)
{
	trienode* cur = head;
	int n = word.length();
	for (int i = 0; i < n; ++i)
	{
		if(cur->child.find(word[i]) == cur->child.end())
			return 0;
		cur = cur->child.at(word[i]);
	}
	return (cur->prefix + cur->end);
}

int main()
{
	trienode* head = new trienode;
	std::string word;
	while(1)
	{
		cout << "1.Insert Word\n2.Search Word\n3.Count Prefix\nEnter Choice: ";
		int choice;
		cin >> choice;
		cout << "Enter Word: ";
		cin >> word;
		if(choice == 1)
		{	
			insertWord(word, head);
		}
		if(choice == 2)
		{
			if(searchWord(word, head))
				cout << "Found\n";
			else
				cout << "Not Found\n";
		}
		if(choice == 3)
		{
			cout << prefixCount(word,head) << '\n';
		}
	}
}