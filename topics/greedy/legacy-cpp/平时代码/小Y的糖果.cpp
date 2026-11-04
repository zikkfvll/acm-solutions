#include<iostream>
using namespace std;
long long n,x,ans,p,t;
int main(){
	cin >> n >> x >> p;
	for(int i = 1;i < n;i++) {
		cin >> t;
		if(t + p > x)
		ans += t + p - x , t = x - p; 
		p = t;
	}
	cout << ans;
  	return 0;
}
