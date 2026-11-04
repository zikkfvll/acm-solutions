#include <bits/stdc++.h>
using namespace std;
long long f(long long n)   
{
	if (n <= 3)
		return 1;
	else
		return f(n-1)+2*f(n-3);
}
int main()
{
	long long a;
	cin >> a;
	cout << f(a) << endl;
	return 0;
}
