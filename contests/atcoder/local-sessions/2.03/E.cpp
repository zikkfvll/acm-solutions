#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define il inline

const int N = 5e5+50;
using namespace std;

int n ,d , res = 1;
int a[N] , dp[N];
il void init() {
    cin >> n >> d;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) dp[i] = 1;
}

il void solve() {
    init();
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++) if(abs(a[i]-a[j]) <= d) dp[i] = max(dp[i],dp[j]+1);
        res = max(res,dp[i]);
    }
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //fre();
    solve();
    return 0;
}
