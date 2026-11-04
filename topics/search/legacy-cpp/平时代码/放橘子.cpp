
#include <stdio.h>
int m,n;
int cnt=0;
 
void dfs(int plate,int apple,int last) 
{
	int i;
	if(plate==n && apple==m)
	{
		cnt++;
		return;
	}
	if(plate==n || apple>m)
		return;
	for(i=last;i<=m;i++)
		dfs(plate+1,apple+i,i);
} 
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		cnt=0;
		scanf("%d%d",&m,&n);
		
		dfs(0,0,0);
		printf("%d\n",cnt);
	}	
	return 0;
}

