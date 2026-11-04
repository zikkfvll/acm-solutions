#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=2e5+100;
int n,a,b,d[N];
bool flag;
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&d[i]);
		d[i]%=a+b;
		if(!d[i]) d[i]=a+b;
	}
	sort(d+1,d+n+1);
	if(d[n]-d[1]+1<=a) flag=true;
	for(int i=2;i<=n;i++)
	{
		if(d[i]-d[i-1]>b&&d[i-1]<=a) flag=true;
	}
	flag?printf("Yes"):printf("No");
	return 0;
} 
