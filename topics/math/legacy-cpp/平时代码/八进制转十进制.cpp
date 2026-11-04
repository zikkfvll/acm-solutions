#include<iostream>
using namespace std;
int main()
{	
	char a[15];
	cin >> a;
	int n = 0;
	for(int i = 0;a[i];i++)
		n = n * 8 + a[i] - '0';
	cout << n << endl;
	return 0;
} 
