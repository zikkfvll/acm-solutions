#include <iostream>
using namespace std;

int n ,a[1000000];

void radix_sort() {  
	//找到最大数字 
	int max_num = a[0];
	for(int i = 1 ; i < n ; i++) {
		max_num = max(max_num , a[i]);
	}
	//基数排序
	int b[10][1000000] ,cnt[10] = {0} ,digit , m;
	for(int unit = 1; unit <= max_num ; unit *= 10) {//max_mun控制循环次数 
		//从一维数组到二维数组 
		for(int i = 0; i < n ; i++) {
			digit = a[i] / unit % 10;
			b[digit][cnt[digit]++] = a[i];
			
		}
		//从二位数组到一维数组
		m = n;
		for(int i= 9 ; i >= 0 ; i--) {
			while(cnt[i]) {
				a[--m] = b[i][--cnt[i]];
			}
		} 
	}
}

int main() {
	//输入
	cin >> n;
	for(int i = 0; i < n ; i++) {
		cin >> a[i];
	} 
	//快速排序
	radix_sort();
	//输出
	for(int i = 0; i < n ; i++) {
		cout << a[i] << " ";
	}
	
    return 0;
}
