//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")


#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define re register
#define il inline
#define N 330000
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

int n, m;
struct node{
    int v,nxt;
} e[N << 2];
int head[N], cnt;
int top[N], fa[N], son[N];
long long siz[N], depth[N];
int sum[N][55];

void add(int u,int v) {
    e[++cnt].nxt = head[u];
    e[cnt].v = v;
    head[u] = cnt;
}

il void fre(){
    freopen(".in", "r", stdin); 
    freopen(".out", "w", stdout);
}

int fpow(int a,int k) {
    int ans = 1;
    while(k > 0) {
        if(k & 1) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        k >>= 1;
    }
    return ans % MOD;
}

il void dfs1(int u , int faa) {
    siz[u] = 1;
    rep(i, 1, 51) sum[u][i] = (sum[faa][i] + (fpow(depth[u], i)));
    for(int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].v;
        if(v == faa) continue;
        depth[v] = depth[u] + 1;
        fa[v] = u; 
        dfs1(v, u);
        siz[u] += siz[v];
        if(siz[v] > siz[son[u]]) son[u] = v;
    }
}

il void dfs2(int u, int faa) {
    top[u] = faa;
    if(son[u]) dfs2(son[u], faa);
    for (int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].v;
        if(v == fa[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}

il int LCA(int x, int y) {
    while(top[x] != top[y]) {
        if(depth[top[x]] > depth[top[y]]) x = fa[top[x]];
        else y = fa[top[y]];
    }
    return depth[x] < depth[y] ? x : y;
}

signed main() {
    //freOI(Name);
    //fre();
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);cout.tie(nullptr);
    read(n);
    rep(i, 1, n - 1){
        int u, v;
        read(u, v);
        add(u, v);
        add(v, u);
    }
    // cout << "debug1" << endl;
    dfs1(1,0); 
    // cout << "debug" <<endl;
    dfs2(1,1);
    read(m);
    while(m--) {
        int u, v, k;
        read(u, v, k);
        int lca = LCA(u, v);
        int tmp = (sum[u][k] - sum[lca][k] + sum[v][k] - sum[fa[lca]][k]) % MOD;
        print(tmp, 1);
    }
    return ~~(0 ^ _ ^ 0);
}

//LCA 树上差分
//数列泼粪
//P4427


/*

9
1 2 
1 3
1 4
2 5
2 6
3 7
3 8
4 9
4
1 2 2
1 3 3
1 4 4
1 5 5

1
1
1
33
*/