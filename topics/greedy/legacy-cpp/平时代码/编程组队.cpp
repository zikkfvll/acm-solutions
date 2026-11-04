#include<iostream>
#include <algorithm>
using namespace std;
int main(){
	int n , a[110] , k = 0;
	cin >> n;
	for(int i = 1;i <= n ; i++) {
		cin >> a[i];
	}
	sort(a + 1 , a + n + 1);
	for(int i = 1 ; i <= n ; i += 2) {
		k += a[i + 1] - a[i];
	}
	cout << k;
	return 0;
}
