// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("Ofast")


#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define re register
#define il inline
#define N 220000
#define M 450
#define MOD 998244353
#define esp 1e-8
#define INF 999999999999999999
#define rep(x, y, z) for(int x = (y); x <= (z); ++x)
#define per(x, y, z) for(int x = (y); x >= (z); --x)
#define debug(format...) fprintf(stderr, format)
#define freOI(Name) do {freopen(Name".in", "r", stdin); freopen(Name".out", "w", stdout);} while(false)
#define pll pair<ll,ll>
#define mkp(x,y) make_pair(x,y)
#define i128 __int128
#define lowbit(x) ((x)&(-(x)))
#define lc (u<<1)
#define rc (u<<1|1)
#define spa << " " <<
#define fi first
#define se second
#define endl '\n'
#define _ 0

namespace fastOI{
    template<class T>
    inline void print(T ret,int flg=0){
        static int sta[35];
        T x=ret;int top=0;
        bool f=(ret<0);
        if(ret<0) x=-x;
        do{sta[top++]=x%10,x/=10;}while(x);
        if(f) putchar('-');
        while(top) putchar(sta[--top]+48);
        if(flg==0)putchar(' ');
        else if(flg==1)putchar('\n');
    }

    template<typename T>
    inline void read(T &ans){
        char ch=getchar();int f=1;ans=0;
        for(;!isdigit(ch);ch=getchar()) ch=='-'?f=-1:f=1;
        for(;isdigit(ch);ch=getchar()) ans=(ans<<3)+(ans<<1)+(ch&15);
        ans*=f;
        return;
    }
    template<typename T,typename ...Args>
    inline void read(T &tmp,Args &...tmps){read(tmp);read(tmps...);}
}

using namespace std;
using namespace fastOI;

int n, q;
int a[N], bl[N], b[N];
int L[M], R[M];
ll l ,r, x, siz;
ll sum[N];

il void fre() {
    freopen("C://Users//y//Downloads//.in", "r", stdin); 
    freopen("C://Users//y//Downloads//a.out", "w", stdout);
}

il ll query() {
    int p = bl[l], q = bl[r];
    ll res = 0;
    if (p == q) {
        rep(i, l, r) if (a[i] <= x) res += a[i];
        return res;
    }
    rep(i, l, R[p]) if (a[i] <= x) res += a[i];
    rep(i, L[q], r) if (a[i] <= x) res += a[i];
    rep(i, p + 1, q - 1) {
        if(b[L[i]] > x) continue;
        res += sum[upper_bound(b + L[i], b + R[i] + 1, x) - b - 1];
    }
    return res;
}

int main() {
    //freOI(Name);.
    //fre();
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);cout.tie(nullptr);
    read(n);
    rep(i ,1, n) read(a[i]);
    rep(i ,1, n) b[i] = a[i];
    int len = sqrt(n), tot = (n - 1) / len + 1;
    rep(i ,1, tot) {
        L[i] = R[i - 1] + 1;
        R[i] = i * len;
    }
    R[tot] = n;
    rep(i, 1, tot) {
        rep(j ,L[i], R[i]) bl[j] = i;
        sort(b + L[i], b + R[i] + 1);
        sum[L[i]] = b[L[i]];
        rep(j, L[i] + 1, R[i]) sum[j] = sum[j - 1] + b[j];
    }
    read(q);
    while (q--) {
        read(l, r, x);
        l ^= siz;
        r ^= siz;
        x ^= siz;
        print(siz = query(), 1);
    }
    return ~~(0 ^ _ ^ 0);
}