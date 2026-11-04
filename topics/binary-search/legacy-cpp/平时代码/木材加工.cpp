#include <iostream>
using namespace std;

int n , k , a[100000];
//n :原木数量
//k : 需要的段数

bool check(int len) {
	int cnt = 0; //记数 ：切出的段数 
	
	for (int i = 0; i < n; i++) {
		cnt += a[i] / len;
	}
	return cnt >= k;
}

int main () {
	int low , high , mid;
	
	//输入 
	cin >> n >> k;
	for(int i = 0; i < n ;i++) {
		cin >> a[i];
	} 
	
	//二分答案\
	
	low = 1;
	high =  100000000;
	while(low <= high) {
		mid = (low + high) / 2; //mid :小段木头长度 
		if(check(mid)) { // 如果ok 
			low = mid + 1;
		}else {
			high = mid - 1;
		} 
	}
	
	//输出
	cout << high << endl; 
	return 0;
} 
