#include <iostream>
#include <vector>
using namespace std;
bool KMP(const string &text, const string &pat)
{
	vector<int> lps(pat.length(),0);
	int i = 1,j = 0;
	while(i < pat.length())
	{
		if(pat[i] == pat[j])
			lps[i++] = ++j;
		else
		{
			if(j!=0)
				j = lps[j-1];
			else
				lps[i++] = 0;
		}
	}
	i = 0,j = 0;
	while(i < text.length() && j < pat.length())
	{
		if(text[i] == pat[j])
		{
			i++;
			j++;
		}
		else
		{
			if(j != 0)
			{
				j = lps[j-1];
			}
			else
				i++;
		}
	}
	return (j == pat.length());
}
int main()
{
	string text = "abcxabcdabcdabcy";
	string pattern = "abcdabcy";
	bool res = KMP(text,pattern);
	if(res) cout << "Pattern found in text";
	else cout << "Pattern not found in text";
}