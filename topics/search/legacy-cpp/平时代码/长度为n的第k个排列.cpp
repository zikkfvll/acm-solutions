#include<iostream>
using namespace std;
int n ,a[13] , mark[13] = {0} , m , cnt = 0;
void f(int k) {
	if(k > n) {
		cnt++;
		if(cnt == m) {
			for(int i = 1 ; i <= n; i++ ){
				printf("%d ", a[i]);
			}
			printf("\n");
			exit(0); 
		}	
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
	cin >> n >> m;	
	f(1);
	return 0;
}

