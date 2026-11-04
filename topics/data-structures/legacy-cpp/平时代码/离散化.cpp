#include <bits/stdc++.h>
using namespace std;

struct Data {
	int num; // 输入的数字 
	int idx; //index : 索引 
};

// 索引 ：唯一的
//通过这个线索能引出数据的叫做索引

bool cmp(Data x , Data y) {
	return x.num < y.num;
}
 
int main (){
	int n , rk[100000] , k; // rk:名次 
	Data a[100000];
	cin >> n;
	for(int i = 0 ; i < n ; i++) {
		cin >> a[i].num;
		a[i].idx = i;
	}
	//排序，从小到大 
	sort(a , a + n , cmp);
	//排名 
	k =  1;
	rk[a[0].idx] = k;
	for(int i = 1 ;i < n ; i++) {//循环的是a数组的下标 
		if(a[i - 1].num != a[i].num) { //不相同 
			k++;
		} 	
			rk[a[i].idx] = k; 
	
	}
	
	//输出
	for(int i = 0 ; i < n ; i++) {
		cout << rk[i] << " ";
	} 
	return 0;
} 

