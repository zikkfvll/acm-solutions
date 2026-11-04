#include <bits/stdc++.h>
using namespace std;
int main (){
	long long n , a[100000] , sum , cnt ;
	
	//输入 
	cin >> n;
	for(int i = 0 ; i < n ; i++) {
		cin >> a[i];
	}
	//排序 
	sort(a , a + n);
	//统计
	sum = cnt = 0; 
	
	for(int i = 0 ; i < n ; i++) {
		if(sum <= a[i]) {
			cnt++;//人在队伍中
			sum += a[i];//把当前人的时间累加进去 
		}
	}
	
	//输出
	cout << cnt <<endl; 
	return 0;
} 
