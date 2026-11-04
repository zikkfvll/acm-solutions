#include<bits/stdc++.h>
using namespace std;
int n , a[11] , b[11]; 
long long sum = 1 , z[11] , ret;

int main() {
	cin >> n;
	for(int i = 1 ;i <= n;++i) {
		cin >>a[i] >> b[i] ;
		sum *= a[i];
	}
	for(int i = 1;i <= n;++i) z[i] = sum /a[i];
	for(int i =1 ; i <= n;++i) 
		for(long long j = z[i] ; j <= 0x7f7f7f7f7f7f; j+=z[i])
			if(j%a[i] == 1) {
				ret += j*b[i]%sum;
				break;
			}
			cout << ret % sum;
	return 0;
}