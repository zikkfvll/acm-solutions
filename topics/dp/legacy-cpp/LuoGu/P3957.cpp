#include <bits/stdc++.h> 
using namespace std;   
struct node {
	int x,s;
}a[510000];
long long dp[510000] , n, d, k ,cnt = -1;
bool check(int g) {
	memset(dp,128,sizeof dp);
	int MAX = d+g;
	int MIN = d-g;
	if(MIN <= 0) MIN =1;
	dp[0] = 0;
	for(int i = 1;i <= n;i++) {
		for(int j= i-1;j>=0;j--) {
			if(a[i].x - a[j].x < MIN) continue;
			if(a[i].x - a[j].x > MAX) break;
			dp[i] = std::max(dp[i] , dp[j]+ a[i].s);
			if(dp[i] >= k) return 1;
		}
	}
	return 0;
}

int main() {
	scanf("%lld %lld %lld",&n,&d,&k);
	for(int i =1;i<=n;i++) scanf("%lld %lld",&a[i].x,&a[i].s);
	int l =0,r=1000,mid = (l+r) >> 1;
	while(l<=r) {
		if(check(mid)) {
			cnt = mid;
			r= mid - 1;
		}
		else l = mid+1;
		mid = (l + r) >> 1;
		
	}
	cout << cnt;
	return 0;
}
