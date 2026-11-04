#include <bits/stdc++.h>
using namespace std;
double f(double x , double n)
{
	if(n==0) return x;
	else{
		return sqrt(n + f(x , n - 1));
	}
}
int main()
{
	double x , n;
	cin >>x >> n;
	printf("%.2f\n" , f(x,n));
	return 0;
}
