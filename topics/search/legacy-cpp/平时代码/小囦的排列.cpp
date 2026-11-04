#include<iostream>
using namespace std;
int n ,a[10];
void f(int k) {
	if(k > n) {
		for(int i = 1 ; i <= n; i++ ){
			printf("%d ", a[i]);
		}
		printf("\n");
	}else {
		for(int i = 1; i <= n; i++) {
			int  flag = false;
			for(int j = 1; j < k; j++) {
				if(a[j] == i) {
					flag = true;
					break;
				}
			}
			if(flag == false && k != i) {
				a[k] = i;
				f(k + 1);
			}
			
		}
	}
	
}
int main() {
	cin >> n;
	f(1);
	return 0;
}
