//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("Ofast")


#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define re register
#define il inline
#define N 220000
#define MOD 998244353
#define esp 1e-8
#define INF 999999999999999999
#define rep(x, y, z) for(int x = (y); x <= (z); ++x)
#define per(x, y, z) for(int x = (y); x >= (z); --x)
#define debug(...) fprintf(stderr, __VA_ARGS__)
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

ll x, y, s, m, k;
int n;
ll a[N], b[N];
ll box[N], nobox[N];
ll sum0[N], sum1[N];
ll res;
ll cnt0, cnt1;
il void fre(){
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
}

int main() {
    //freOI(Name);
    //fre();
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);cout.tie(nullptr);
    read(x, y, s, m, k);
    read(n);
    rep(i, 1, n) read(a[i]);
    rep(i, 1, n) {
        read(b[i]);
        if(b[i] == 1) box[++cnt1] = a[i];
        else nobox[++cnt0] = a[i]; //可以vector啊
    }
    sort(box + 1, box + cnt1 + 1, greater<ll>());
    sort(nobox + 1, nobox + cnt0 + 1, greater<ll>());
    rep(i, 1, cnt0) sum0[i] = sum0[i - 1] + nobox[i];
    rep(i, 1, cnt1) sum1[i] = sum1[i - 1] + box[i];
    ll c0 = k * x, c1 = k * x + y;
    ll maxx = m / k;
    rep(i, 0, cnt1) {
        ll need = i * c1;
        if(need > s) break;
        if(i > maxx) break;
        ll minn = min(min(cnt0, maxx - i), (s - need) / c0);
        res = max(res, sum1[i] + sum0[minn]);
    }
    print(res, 1);
    return ~~(0 ^ _ ^ 0);
}
