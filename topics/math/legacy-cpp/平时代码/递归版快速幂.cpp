#include <bits/stdc++.h>
using namespace std;

long long x;
int y , z ;

long long f(int k) {
	if(k == 0) {
		return 1;
	}else {
		long long t = f(k / 2);
		if(k % 2 == 1) {
			return t * t % z * x % z;
		} else {
			return t * t % z; 
		}
	}
}
int main()
{

	cin >> x >> y >> z;
	cout << f(y) << endl;
	return 0;
}

