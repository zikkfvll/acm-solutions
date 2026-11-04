#include<iostream>
using namespace std;
int n ,a[10] , mark[10] = {0};
void f(int k) {
	if(k > n) {
		for(int i = 1 ; i <= n; i++ ){
			printf("%d ", a[i]);
		}
		printf("\n");
	}else {
		for(int i = 1; i <= n; i++) {
			if(mark[i] == 0) {
				a[k] = i;
				mark[i] = 1;
				f(k + 1);
				mark[i] = 0;
			}
			
		}
	}
	
}
int main() {
	cin >> n;
	f(1);
	return 0;
}
