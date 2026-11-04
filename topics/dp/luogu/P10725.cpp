//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")


#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define re register
#define il inline
#define N 1000010
#define MOD 998244353
#define esp 1e-8
const int INF = 1e9 + 10;
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

int n, to[N << 2], nxt[N << 2], ver[N];
int c[N], idx, res, dp[N][2];
void add(int x,int y) {
    to[++idx] = y, nxt[idx] = ver[x], ver[x] = idx;
}

il void fre(){
    freopen(".in", "r", stdin); 
    freopen(".out", "w", stdout);
}

il void dfs(int u,int fa) {
    dp[u][0] = dp[u][1] = -INF;
    dp[u][c[u]]=0;
    for(int i = ver[u]; i; i = nxt[i]) {
        int v = to[i];
        if(v == fa) continue;
        dfs(v, u);
        res = max(res, max(dp[u][1] + dp[v][0], dp[u][0] + dp[v][1]) + 1);
        dp[u][0] = max(dp[u][0], dp[v][0] + 1);
        dp[u][1] = max(dp[u][1], dp[v][1] + 1);
    }
}

int main() {
    //freOI(Name);
    //fre();
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);cout.tie(nullptr);
    read(n);
    rep(i ,1 ,n) read(c[i]);
    rep(i, 1, n - 1) {
        int u, v;
        read(u, v);
        add(u, v), add(v, u);
    }
    dfs(1, 0);
    print(res, 1);
    return ~~(0 ^ _ ^ 0);
}
