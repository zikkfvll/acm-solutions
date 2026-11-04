#include <iostream>
using namespace std;
int main()
{
	int m, n, t, e;
	cin >> m >> n;
	t = m * n;
	if (m < n) {
		int temp;
		temp = m;
		m = n;
		n = temp;
	}
	e = m % n;
	while (e != 0) {
		m = n;
		n = e;
		e = m % n;
	}
	cout << n <<endl; 
	cout << t / n << endl;
	return 0;
}
