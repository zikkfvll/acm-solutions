#include <bits/stdc++.h>
using namespace std;

long long n ,tot,a[1100000];

long long dfs(long long c) {
	a[++tot] = c;
	if(c > 9e17) return 0;
	for(int i = 0;i <= 1;++i) {
		dfs(c*10+i);
	}
} 

int main() {
	cin >> n;
	dfs(1);
	sort(a+1,a+1+tot);
	for(int i = 1;i <= tot ;++i) {
		if(a[i] % n == 0) {
			cout<< a[i]/n;
			return 0;
		}
	}
	printf("No Solution");
	return 0;
}
