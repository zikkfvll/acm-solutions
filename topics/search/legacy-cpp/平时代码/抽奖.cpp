#include<iostream>
using namespace std;
int n ,a[10];
void f(int k) {
	if(k > n) {
		for(int i = 1 ; i <= n; i++ ){
			cout << a[i] <<" "; 
		}
		cout << endl;
	}else {
		for(int i = 1; i <= n; i++) {
			a[k] = i;
			f(k + 1);
		}
	}
	
}
int main() {
	cin >> n;
	f(1);
	return 0;
}
