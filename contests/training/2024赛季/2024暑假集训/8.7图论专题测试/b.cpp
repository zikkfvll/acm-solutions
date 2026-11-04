//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")


#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define re register
#define il inline
const int N = 1e5 + 100; 
#define M 2200000
#define MOD 998244353
#define esp 1e-8
const int INF = 0x3f3f3f3f;
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

struct Edge{
    int to,last,k;
}e[M];
int n, m, cnt;
int h[N], pre[N], dis[N];
bool vis[N];

il void add(int u, int v, int w) {
	e[++cnt].to = v;
	e[cnt].last = w;
	e[cnt].k = pre[u];
	pre[u] = cnt;
}

struct node{
    int v, h, dis;
    node(int _v = 0,int _h = 0,int _dis = 0) : v(_v),h(_h),dis(_dis){}
    bool operator < (const node & s) const{
        return h == s.h ? dis > s.dis : h < s.h;
    }
};

il int prim() {
    int sum = 0; cnt = 0;
    memset(dis, INF, sizeof dis);
    priority_queue<node> q;
    dis[1] = 0;
    q.push(node(1, h[1], 0));
    while(!q.empty()) {
        auto u = q.top(); q.pop();
        if(vis[u.v]) continue;
        vis[u.v] = 1;
        sum += dis[u.v], cnt++;
        // cout << "u : " << u.v << "cnt : " << cnt;
        // cout << "sum : " << sum << endl;
        for(int i = pre[u.v]; i; i = e[i].k) {
            int v = e[i].to;
            if(!vis[v] && e[i].last < dis[v]) {
                dis[v] = e[i].last;
                q.push(node(v, h[v], e[i].last));
            }
        }
    }
    return sum;
}

il void fre(){
    freopen(".in", "r", stdin); 
    freopen(".out", "w", stdout);
}

signed main() {
    //freOI(Name);
    //fre();
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);cout.tie(nullptr);
    read(n, m);
    rep(i, 1, n) read(h[i]);
    rep(i, 1, m) {
        int u, v, k;
        read(u, v, k);
        if(h[u] >= h[v]) add(u, v, k);
        if(h[v] >= h[u]) add(v, u, k);
    }
    int res = prim();
    print(cnt, 0); print(res, 1);
    return ~~(0 ^ _ ^ 0);
}

//P2573
//最小生成树