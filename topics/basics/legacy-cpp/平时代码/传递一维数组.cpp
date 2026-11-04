#include <iostream>
using namespace std;

int getmax(int *a,int n){
	int max = a[0];
	for(int i = 1; i < n; i++){
		if(a[i] > max){
			max = a[i];
		}
	}
	return max;
} 

int getmin(int *a , int n){
	int min = a[0];
	for(int i = 1; i < n; i++){
		if(a[i] < min){
			min = a[i];
		}
	}
	return min;
}

int main (){
	int n,k;
	for(int i = 0 ; i < 3 ;i++){
		cin >> n;
		int a[n] = {0};
		for(int i = 0;i < n ; i++){
			cin >> k;
			a[i] = k;
		}
	cout << getmax(a,n) << " " << getmin(a,n) << endl;
	}
	
	return 0;
} 
