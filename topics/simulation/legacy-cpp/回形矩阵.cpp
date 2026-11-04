#include<iostream>
using namespace std;
int main()
{
	int i,j,n,a[100][100],y=1,k;
	cin >> n;
	for(i = 1;i <= (n + 1) / 2;i++)
	{
		for(j = i;j <= n - i + 1;j++) 
		{
			for( k = i ; k <= n - i + 1 ; k++)
			a[j][k] = y;
		}
		y++;
	}
	for(i = 1 ; i <= n ; i++)
	{
		for(j = 1 ; j <= n ; j++) 
			cout << a[i][j] << " ";
		cout << endl;
	}
	return 0;
}
