#include <bits/stdc++.h>
using namespace std;
long long G(long long x, long long y)   
{
	if (x <= 0 || y <= 0)
		return 1;
	else
		return G(x - 1 , y) + 2 * G(x - 1 , y - 1) + 3 * G(x , y - 1);
}
int main()
{
	long long n , m;
	cin >> n >> m;
	cout << G(n , m) << endl;
	return 0;
}
