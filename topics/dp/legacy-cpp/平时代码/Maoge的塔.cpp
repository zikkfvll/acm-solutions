#include <iostream>
#include<algorithm>
using namespace std;
int main (){
	long long n ,d , a[1005], b[1005] = {0 , 1} , c = 0;
	cin >> n >> d;
	for(int i = 0;i < n ; i++) {
		cin >> a[i];
	} 
	
	sort(a , a+n);
	
	for(int i = 1; i <= n ;i++) {
		for(int j = 0;j < i ; j++) {
			if(a[j] + d <= a[i]){
				b[i] += b[j] % 1000000007;
			}
		}
		b[i] = b[i] + 1;
		c += b[i] % 1000000007;
		
	}
	cout << c % 1000000007<< endl;
	return 0;
} 
