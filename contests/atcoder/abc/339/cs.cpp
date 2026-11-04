#include <bits/stdc++.h>
using namespace std;
#define MAXN 200001
#define MAXM 450

int n, q;
int a[MAXN], bl[MAXN], b[MAXN];
int L[MAXM], R[MAXM];
long long l, r, x, lans;
long long sum[MAXN];

long long query(){
    int p(bl[l]), q(bl[r]);
    long long res(0);
    if (p == q){
        for (int i(l); i<=r; ++i){
            if (a[i] <= x) res += a[i];
        }
        return res;
    }

    for (int i(l); i<=R[p]; ++i){
        if (a[i] <= x) res += a[i];
    }
    for (int i(L[q]); i<=r; ++i){
        if (a[i] <= x) res += a[i];
    }
    for (int i(p+1); i<q; ++i){
        if (b[L[i]] > x) continue;
        res += sum[upper_bound(b+L[i], b+R[i]+1, x)-b-1];
    }
    return res;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i(1); i<=n; ++i) cin >> a[i];
    for (int i(1); i<=n; ++i) b[i] = a[i];
    int len(sqrt(n)), tot((n-1)/len+1);
    for (int i(1); i<=tot; ++i){
        L[i] = R[i-1] + 1;
        R[i] = i * len;
    }
    R[tot] = n;

    for (int i(1); i<=tot; ++i){
        for (int j(L[i]); j<=R[i]; ++j) bl[j] = i;
        sort(b+L[i], b+R[i]+1);
        sum[L[i]] = b[L[i]];
        for (int j(L[i]+1); j<=R[i]; ++j) sum[j] = sum[j-1] + b[j];
    }

    cin >> q;
    while (q--){
        cin >> l >> r >> x;
        l ^= lans;
        r ^= lans;
        x ^= lans;
        cout << (lans = query()) << '\n';
    }

    return 0;
}
