#include <bits/stdc++.h> 
using namespace std;
int n, a[110000], ans[2][110000];


int main() {
	cin >> n;
	if (n % 2 == 0) {
		cout << -1;
		return 0;
	}
	for (int i = 0; i < n; i ++) {
		ans[0][(2 * i + 1) % n] = i;
		ans[1][(2 * i + 1) % n] = (i + 1) % n;
	}
	for (int i = 1; i <= n; i ++) cin >> a[i];
	for (int i = 0; i < 2; i ++){
		for (int j = 1; j <= n; j ++) cout << ans[i][a[j] ] << " ";
		cout << endl;
	}
	return 0;
}
