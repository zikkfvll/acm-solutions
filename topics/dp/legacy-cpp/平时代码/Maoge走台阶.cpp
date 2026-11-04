#include <iostream>
using namespace std;
int main ()
{
	int n , k;
	int a[100001] = {1} , sum[100001] = {1};
	cin >> n >> k;
	for(int i = 1; i <= k; i++){
		a[i] = sum[i - 1] ;
		sum[i]= sum[i - 1]+ a[i];
		sum[i] %= 1000000007;
	}
	for(int i = k + 1 ; i <= n ;i++){
		for(int j = 1 ; j <= k; j++){
			a[i] = a[i] + a[i - j];
			a[i] %= 1000000007;
		}
	}
	cout << a[n] <<endl;
   return 0;
}

