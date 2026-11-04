#include <iostream>
#include <algorithm>
using namespace std;

int n , m , x[300000];
//n :牛舍数量 
//m : 已有牛数

bool check(int dist) {
	int cnt = 1 , p = x[0]; //cnt记数 ：能放牛的数量 
	
	for (int i = 0; i < n; i++) {
		if(x[i] - p >= dist) {
			cnt++;
			p = x[i];
		}
	 
	}
	return cnt >= m;
}

int main () {
	int low , high , mid;
	
	//输入 
	cin >> n >> m;
	for(int i = 0; i < n ;i++) {
		cin >> x[i];
	} 
	
	//排序
	sort(x,x + n); 
	
	//二分答案	
	low = 1;
	high =  1e9;
	while(low <= high) {
		mid = (low + high) / 2; //mid :小段木头长度 
		if(check(mid)) { // 是否满足条件 
			low = mid + 1;
		}else {
			high = mid - 1;
		} 
	}
	
	//输出
	cout << high << endl; 
	return 0;
} 
