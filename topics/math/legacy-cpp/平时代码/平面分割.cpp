#include<iostream>
long long a[4];
using namespace std;
int main()
{
	long long n;
	cin >> n;
	a[1]=2;
	a[2]=4;
	a[3]=7;
	for(long long i=3; i<=n; i++)
	{
		a[3]=a[2]+i;
		a[2]=a[3];
	}
	if(n==0)
		cout<<1<<endl;
	else if(n==1)
		cout<<2<<endl;
	else if(n==2)
		cout<<4<<endl;
	else
		cout<<a[3]<<endl;
	return 0;
}
