#include <iostream>
using namespace std;
int main ()
{
	int n , a[1001]= {0,1};
	cin >> n;
	for(int i = 2 ;i <= n;i++){
		a[i] = 1; 
		for(int j= i/ 2; j >= 1 ; j--){
			a[i] += a[j];
		}
	}
	cout << a[n] <<endl;
   return 0;
}

