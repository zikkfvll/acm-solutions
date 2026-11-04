#include<stdio.h>
void print(int n)
{
	if(n==0) return;
	else{
		printf("%d",n%10);
		print(n/10);
		return;
	}
}
int main()
{
	long n;
	scanf("%d",&n);
	print(n);
	return 0;
}
