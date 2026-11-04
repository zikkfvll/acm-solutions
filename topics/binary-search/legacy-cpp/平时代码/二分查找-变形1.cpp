#include <iostream>
using namespace std;
int main (){
	int n , m ,a[1000001];
	int l , mid ,r;
	
    cin >> n >> m;
    
    //输入 
	for(int i = 1; i <= n; i++) { // 从序号1开始 
    	cin >> a[i];
	}
	
	//二分查找
	//初始化边界 
	l = 1;
	r = n;
	
	//循环查找 
	 
	while(l <= r) {
		mid = (l + r) / 2;
		if(a[mid] <= m) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	 
	 //输出
	 
	 	cout << l << endl; 
	 
	return 0;
} 
