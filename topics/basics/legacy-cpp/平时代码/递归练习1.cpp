#include<iostream>
using namespace std;
int n;
void f(int k) {
	if(k == 0) {
		return;
	}else {
		cout<<n / k << " ";
		f(k / 2);
	}
}
int main() {
	int k;
	cin >>n;
	k = 1;
	for(int i =1 ; k <= n;i++) {
		k *= 2;
	}
	
	f(k);
}
