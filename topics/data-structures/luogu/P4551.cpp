//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("Ofast")


#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define re register
#define il inline
#define N 100010
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
#define u ((x >> i) & 1)

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

int n;
int h[N], e[N << 1], w[N << 1], nxt[N << 1], idx;
int nex[N << 5][2], cnt[N], res, t = 1;

il void add(int uu, int v, int c) {
    e[idx] = v;
    w[idx] = c;
    nxt[idx] = h[uu];
    h[uu] = idx++;
}

il void insert(int x) {
    int p = 1;
    per(i, 30, 0) {
        if(!nex[p][u]) nex[p][u] = ++t;
        p = nex[p][u];
    }
}

il int query(int x) {
    int ans = 0, p = 1;
    per(i, 30, 0) {
        if(nex[p][u ^ 1]) p = nex[p][u ^ 1], ans += (1 << i);
        else p = nex[p][u];
    }
    return res = (res > ans ? res : ans);
}

il void dfs(int x, int lt) {
    insert(cnt[x]); query(cnt[x]);
    for(int i = h[x]; ~i; i = nxt[i]) {
        if(e[i] == lt) continue;
        cnt[e[i]] = cnt[x] ^ w[i];
        dfs(e[i], x);
    }
}

int uu, v, c;

int main() {
    //freOI(Name);
    //fre();
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);cout.tie(nullptr);
    memset(h, -1, sizeof h);
    read(n);
    rep(i, 1, n - 1) {
        read(uu, v, c);
        add(uu, v, c); add(v, uu, c);
    }
    dfs(1, 0);
    print(res, 1);
    return ~~(0 ^ _ ^ 0);
}
