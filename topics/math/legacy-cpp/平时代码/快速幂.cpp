#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long a , b , p = 1000000007 , c;
	cin >> a >> b;
	
	c = 1;
	while(b) {
		if(b & 1) {
			c = c * a % p;
		}
		a = a * a % p;
		b >>= 1;
	}
	
	cout << c << endl;
	
	return 0;
}

