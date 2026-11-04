#include <iostream>
using namespace std;
int checkmax(int *a ,int n)
{
	int maxx = a[0];
	for(int i =1; i < n ; i++){
		maxx = max(a[i], maxx);
	}
	return maxx;
}

int checkmin(int *a ,int n)
{
	int minn = a[0];
	for(int i =1; i < n ; i++){
		minn = min(a[i], minn);
	}
	return minn;
} 

int main()
{
    int a[100] ;
    int n;
	cin >> n;
	for(int i = 0 ; i <n ;i++){
		cin >>a[i];
	} 
	cout<<checkmax(a , n) << " " << checkmin(a , n);
    return 0;
}
