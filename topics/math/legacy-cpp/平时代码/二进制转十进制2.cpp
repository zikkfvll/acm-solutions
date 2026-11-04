#include<iostream>
using namespace std;
int main()
{	
	char a[35];
	cin >> a;
	int n = 0;
	for(int i = 0;a[i] != '\0';i++)
		n = n * 2 + a[i] - '0';
	cout << n << endl;
	return 0;
} 
