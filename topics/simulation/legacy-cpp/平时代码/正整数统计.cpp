#include <bits/stdc++.h>
using namespace std;
int main (){
	int  n , a[10000000] , cnt ;
	
	//输入 
	cin >> n;
	for(int i = 0 ; i < n ; i++) {
		cin >> a[i];
	}
	//排序 
	sort(a , a + n);//从小到大 
	
	// 统计 输出
	cnt = 1; // 先把a[0]算进去 
	for(int i = 1 ; i < n ; i++ ) {
		if(a[i - 1] == a[i]) { // 相邻数字相等 
			cnt++;
		} else { //相邻数字不同 
			cout << a[i - 1] << " " << cnt << endl;
			cnt = 1;
		}
	}
	cout << a[n - 1] << " " << cnt << endl;
	
	return 0;
} 

