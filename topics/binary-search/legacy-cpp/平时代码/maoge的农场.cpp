#include <iostream>
using namespace std;
int n , m , a[100000];
//n : 天数 m :给定的周期数 


bool check(int money) {
	int cnt = 1 , sum = 0; //根据money记录所需的周期数
	
	for(int i = 0 ; i < n ; i++) { //检查每一天 
		if(sum + a[i] <= money) {
			sum += a[i];
		} else {
			cnt++;
			sum = a[i];
		}
	} 
	return cnt <= m;
}

int main() {
	int l ,r , mid;
	int maxn = 0,sum = 0;
	
	//输入 
	cin >> n >> m;
	for(int i = 0; i< n ; i++) {
		cin >> a[i];
		maxn = max(maxn , a[i]);
		sum += a[i];
	}
   
   
	//二分答案
	l = maxn;
	r = sum;
	while(l <= r) {
		mid = (l + r) / 2;
		if(check(mid)) {
			r = mid - 1;
		} else {
			l = mid +1;
		}
	}
	
	cout << l << endl;
	
    return 0;
}
