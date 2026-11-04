#include<iostream>
#include<climits> 
#include<iomanip>
using namespace std;
int main() {
	int a[1100];
	int n;
	while(cin >> n) {
		int sum = 0;
		int max =- INT_MAX;
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
			if(a[i] > max)
				max = a[i];
			sum += a[i];
		}
		if(max >= sum-max){
			cout << fixed << setprecision(1) <<( sum - max) * 1.0 << endl;
		}	
		else{
			cout << fixed << setprecision(1) <<sum*1.0 / 2 << endl;
		}		
	}
	return 0;
}
