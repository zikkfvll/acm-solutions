
#include <bits/stdc++.h>
#define ll long long
#define N 100010
#define rep(x,y,z) for(int x=(y);x<=(z);++x)
#define endl '\n'

using namespace std;

ll n, q;
ll a[N], s[N], c[N], p[N];

ll calc(ll x) {
    if(x == 0) return 0;

    ll i = lower_bound(c+1, c+n+1, x) - c;
    ll k = x - c[i-1];

    return p[i-1] + s[k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    rep(i,1,n) {
        cin >> a[i];
    }

    rep(i,1,n) {
        s[i] = s[i-1] + a[i];
        c[i] = c[i-1] + i;
        p[i] = p[i-1] + s[i];
    }

    while(q--) {
        ll l, r;
        cin >> l >> r;

        cout << calc(r) - calc(l-1) << endl;
    }

    return 0;
}
