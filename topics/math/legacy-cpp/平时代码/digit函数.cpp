#include <iostream>
using namespace std;
void f(int i , int m ,string n)
{
	if(i == m) cout << n[i];
	else f(i - 1, m ,n);
	
}
int main()
{
	string n;
	int k;
	cin >> n >> k;
	if( k > n.size()) cout << 0;
	else f(n.size() - 1, n.size() - k ,n);
	return 0;
}
