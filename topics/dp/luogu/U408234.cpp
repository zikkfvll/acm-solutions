#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n, t1, t2;
long long res = 0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> t1 >> t2;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<long long> dp(n + 1);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= t1; ++j) 
            if (i - j >= 0) dp[i] = (dp[i] + dp[i - j] + (i - j == 0 ? 0 : a[i - j - 1])) % MOD;
        if (i > t1) dp[i] = (dp[i] + dp[i - t1] * 2) % MOD;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) res = (res + dp[n - i] * a[i]) % MOD;
    cout << res << endl;
    return 0;
}
