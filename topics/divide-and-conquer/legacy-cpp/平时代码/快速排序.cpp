#include <iostream>
using namespace std;

int partition(int *a , int low , int high) {
	int pivot = a[high - 1];
	int cnt = low;//记录比pivot小的数字的个数，同时也是下标使用 
	
	for(int j = low ; j < high - 1 ; j++) {
		if(a[j] < pivot) {
			swap(a[cnt] , a[j]);
			cnt++;
		}
	}
	swap (a[cnt] , a[high - 1]);
	
	return cnt;
}

void quick_sort(int *a , int low, int high) {  //递归函数 
	if(low < high - 1) {//至少有2个数字才能排序 
		//分
		int idx = partition(a , low , high);//分一次，得到下标 
		quick_sort(a, low , idx);//排序左边的 
		quick_sort(a , idx + 1 , high);//排序右边的 
	}
}

int main() {
	int n ,a[1000000];
	
	//输入
	cin >> n;
	for(int i = 0; i< n ; i++) {
		cin >> a[i];
	} 
	
	//快速排序
	quick_sort(a , 0 , n);
	
	
	//输出
	for(int i = 0; i< n ; i++) {
		cout << a[i] << " ";
	}
	
    return 0;
}
