#include<bits/stdc++.h>
using namespace std;
int main()
{
	int s[10] = {0} , a[10] = {0} , b[10] = {0} , x = 0 , y = 0;
	for (int i = 0;i < 10;i++) {
		cin>>s[i];
		if (s[i] % 2 == 1 ){
			a[x] = s[i];
			x++;
		}
		else {
			b[y] = s[i];
			y++;
		}
	}
	sort(a , a+x);
	sort(b , b+y);
	for (int i = x - 1 ; i >= 0 ; i--)
		cout << a[i] << ' ';
	for (int i = 0 ; i < y ; i++)
		cout << b[i] << ' ';
	return 0;
}
