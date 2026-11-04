#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int len = s.length();
	int n = 0;
	for(int i = 0 ; i < len ; ++i)
	{
		if(s[i] == '1')
			n += pow(2,len-1-i);
	}
	cout<<n;
} 
