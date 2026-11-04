#include <iostream>
using namespace std;
int n , l , r, a = 0 , b = 0 , s[110] , sum = 0; 
int main (){
	cin >> n;
	for(int i = 0; i< n;i++) {
		cin >>s[i];
		sum += s[i];
	}
	cin >> l >> r;
	for(int i = 0; i < n ; i++) {
		if(s[i] > r) {
			a+=s[i] - r;
		}
		if(s[i] < l) {
			b +=l - s[i];
		}
	}
	if(sum > n * r||sum < n * l) {
		cout << "-1" <<endl;;
	} 
	else {
		cout<< max(a,b) << endl;
	}
	return 0;
} 
