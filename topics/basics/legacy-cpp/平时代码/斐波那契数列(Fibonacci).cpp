#include <bits/stdc++.h>
using namespace std;
int fun(int n)   
{
	if (1 == n||2==n)
		return 1;
	else
		return fun(n - 1) + fun(n - 2);
}
int main()
{
	int a;
	cin >> a;
	cout << fun(a) << endl;
	return 0;
}
