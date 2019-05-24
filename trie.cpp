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
	bool end;
	int prefix;
	trienode()
	{
		end = false;
		prefix = 0;
	}
	~trienode()
	{
		trienode* temp;
		for(auto i : child)
		{
			temp = i.second;
			delete temp;
		}
		child.clear();
	}
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

trienode* removeWord(trienode* head,const std::string &s,int index = 0)
{
	if(head == NULL)
		return NULL;
	if(index == s.length())
	{
		if(head->end)
			head->end = false;
		if(head->child.empty())
		{
			delete head;
			head = NULL;
		}
		return head;
	}
	head->child[s[index]] = removeWord(head->child[s[index]],s,index+1);
	head->prefix--;
	if(head->child[s[index]] == NULL)
		head->child.erase(s[index]);
	if(head->child.empty() && head->end == false)
	{
		delete head;
		head = NULL;
	}
	return head;
}
int main()
{
	trienode* head = new trienode;
	std::string word;
	while(1)
	{
		cout << "1.Insert Word\n2.Search Word\n3.Count Prefix\n4.Remove Word\nEnter Choice: ";
		int choice;
		cin >> choice;
		cout << "Enter Word: ";
		cin >> word;
		switch(choice)
		{
			case 1:
				insertWord(word, head);
				break;
			case 2:
				if(searchWord(word, head))
					cout << "Found\n";
				else
					cout << "Not Found\n";
				break;
			case 3:
				cout << prefixCount(word,head) << '\n';
				break;
			case 4:
				removeWord(head,word);
				break;
			default:
				cout << "Invalid Choice\n";
		}
	}
	delete head;
}
