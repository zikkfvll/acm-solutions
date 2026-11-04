//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("Ofast")


#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define re register
#define il inline
const int N = 1e5 + 1000;
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


il void fre(){
    freopen("detect3.in", "r", stdin); 
    freopen("detect.out", "w", stdout);
}

struct cow {
    int d, v, a;
}c[N];

int n, m, L, V;
int ce[N];

bool suba = true, subb = true, subc = true; 
il void sol() {
    cin >> n >> m >> L >> V;
    rep(i, 1, n) {
        cin >> c[i].d >> c[i].v >> c[i].a;
        if(c[i].a != 0) suba = false;
        if(c[i].a >= 0) subc = false;
        if(c[i].a <= 0) subb = false;
    }
    rep(i, 1, m) cin >> ce[i];
    int maxd = ce[m];
    if(suba) {
        int res = 0;
        rep(i, 1, n){
            if(c[i].v > V && c[i].d < maxd) {
                res++;
            }
        }
        if(res!=0)cout<< res << " " << m - 1<< endl; 
        else cout << res << " " << m <<endl; 
    }
}

int main() {
    //freOI(Name);
    fre();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while(t--) sol();
    return ~~(0 ^ _ ^ 0);
}
