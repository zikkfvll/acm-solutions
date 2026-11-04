#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,f;
	cin >> n;
	int cnt = 0;
		for (int i = 2; i <= n; i++)
		{
			f=1;
			for(int j = 2; j <=sqrt(i); j++)
			{
				if(i%j==0){
					f=0;
					break;
				}
			}
			if(f){
			cnt++;
			}
		}
	cout << cnt<< endl;
	return 0;
}

