#include <iostream>
using namespace std;

int n , m , a[300000];

bool check(int len) {
	int cnt = 0; 
	
	for (int i = 0; i < m; i++) {
		cnt += a[i] / len + (a[i] % len > 0); //cnt :累加所需的元素
	 
	}
	return cnt <= n;
}

int main () {
	int low , high , mid;
	
	//输入 
	cin >> n >> m;
	for(int i = 0; i < m ;i++) {
		cin >> a[i];
	} 
	
	//二分答案	
	low = 1;
	high =  1e9;
	while(low <= high) {
		mid = (low + high) / 2;  
		if(check(mid)) { // 是否满足条件 
			high = mid - 1;
		}else {
			low = mid + 1;
		} 
	}
	
	//输出
	cout << low << endl; 
	return 0;
} 
