#include<bits/stdc++.h>
using namespace std;
int main(){
	int n[10] , m[10] = {0} , max1 = INT_MAX , ans = 0;
	for(int i = 1 ; i <= 8 ; i++){
		cin >> n[i];
	}
	for(int i = 1 ; i <= 5 ; i++){
		int max2 = 0;
		for(int j = 1 ; j <= 8 ; j++){
			if(n[j] > max2 && n[j] < max1){
				m[i] = j;
				max2 = n[j];
			}
		}
		ans += max2;
		max1 = max2;
	}
	sort(m + 1 , m + 6);
	cout << ans << endl;
	for(int i = 1 ; i <= 5; i++){
		cout << m[i] << " ";
	}
	return 0;
}
