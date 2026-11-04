//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")


#include <bits/stdc++.h>
#define ll long long
#define re register
#define il inline
const int N = 5e4 + 500;
#define MOD 1000000007
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

int n, m, pu[N], pv[N];
int cnt, head[N], to[N << 1], nxt[N << 1];
int dfncnt, dfn[N], siz[N], depth[N], fa[N], son[N], top[N];

void add(int u,int v){
	to[cnt] = v;
    nxt[cnt] = head[u];
    head[u] = cnt++;
}

void dfs1(int u,int faa){
    siz[u] = 1, fa[u]= faa;
	depth[u] = depth[fa[u]] + siz[u];
	for(int i = head[u]; ~i; i = nxt[i]){
		int v = to[i];
		if(v == faa) continue;
		dfs1(v, u);
        siz[u] += siz[v];
		if(siz[v] > siz[son[u]]) son[u] = v;
	}
}

void dfs2(int u,int faa){
	dfn[u] = ++dfncnt, top[u] = faa;
	if(son[u]) dfs2(son[u], faa);
	for(int i = head[u]; ~i; i = nxt[i]){
		int v = to[i];
		if(v == fa[u] || v == son[u]) continue;
		dfs2(v,v);
	}
}

struct STree{
	int t[N<<1];
	void build(){
		rep(i, 0, (N << 1) - 1) t[i] = MOD;
	}
	void add(int l, int r, int w){
		for(l = l + N - 1, r = r + N + 1; l ^ r ^ 1; l >>= 1, r >>= 1){
			if(~l&1)t[l ^ 1] = min(t[l ^ 1], w);
			if( r&1)t[r ^ 1] = min(t[r ^ 1], w);
		}
	}
	int query(int x){
		int ans = MOD;
		for(x += N; x; x >>= 1 ) ans = min(ans, t[x]);
		return ans;
	}
}T;

void update(int u,int v,int w){
	while(top[u] != top[v]){
		if(depth[top[u]] < depth[top[v]]) swap(u,v);
		T.add(dfn[top[u]], dfn[u],w);
		u = fa[top[u]];
	}
	if(depth[u] < depth[v]) swap(u, v);
	T.add(dfn[v] + 1, dfn[u], w);
}


il void fre(){
    freopen("C://Users//y//Downloads//P4374_5.in", "r", stdin); 
    freopen("C://Users//y//Downloads//a.out", "w", stdout);
}

int main() {
    //freOI(Name);
    fre();
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);cout.tie(nullptr);
    read(n, m);
	memset(head, -1, sizeof head);
	rep (i, 2, n) {
        read(pu[i], pv[i]);
        add(pu[i], pv[i]);
        add(pv[i], pu[i]);
    }
    dfs1(1,0), dfs2(1, 1);
    T.build();
    while (m--){
		int u,v,w;
		read(u, v, w);
		update(u, v, w);
	}
    rep (i,2,n){
		int ans = T.query(max(dfn[pu[i]], dfn[pv[i]]));
		if(ans == MOD) puts("-1");
		else print(ans, 1);
	}
    return ~~(0 ^ _ ^ 0);
}

//P4374