#include<bits/stdc++.h>
using namespace std;
#define IN 0x3f3f3f3f
int n;
double x[61000];
double y[61000];

double check()
{
	double d , m = IN; 
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = i + 1 ; j < n ; j++)
		 {
		 	d=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
		 	if(d < m)
             m = d;
		 }  
	}
	
	return m;
} 

int main()
{
	cin >> n;
	
	int i;
	for(i = 0 ; i < n ; i++) {
		cin >> x[i] >> y[i];
	}

	
	cout <<setiosflags(ios::fixed)<<setprecision(2) << sqrt(check());
	return 0;
}
