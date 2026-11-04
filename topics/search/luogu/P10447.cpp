//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("Ofast")


#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define re register
#define il inline
#define N 1000010
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
    freopen("C://Users//y//Downloads//.in", "r", stdin); 
    freopen("C://Users//y//Downloads//a.out", "w", stdout);
}

const double delta = 0.9999777;
const double MAX_TIME = 0.8;
int n;
int p[22],mp[22][22];
int res;
double resx = 0, resy = 0, t, r;


double Rcalc(double x,double y,double a,double b) {
    return sqrt((x-a)*(x-a)+(y-b)*(y-b));
}

int calc() {
    int ans = 0;
    rep(i, 1, n - 1) 
        ans += mp[p[i]][p[i + 1]];
    return ans;
}

inline void sa() {
    double T = 3000;
    int now;
    now = res = calc();
    while (T > 1e-18) {
        for(int qwq = 1;qwq <= 100; ++qwq){    
            int u = rand() % n + 1, v = rand() % n + 1;
            if(u == 1 || v == 1 || u == n || v == n) continue;
            swap(p[u], p[v]);
            int ew = calc();
            int newDelta = ew - now;
            if(newDelta < 0|| exp(-newDelta/T)*RAND_MAX>rand()){
                now=ew;
                res=min(res,now);
            }
            else swap(p[u],p[v]);
            T *= delta;
        }
    }
}

inline void solve() {
    double st = clock();
	while(1){
		sa();
		if(clock() - st > 950) break;
	}
}

signed main() {
    //freOI(Name);
    //fre();
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    srand(20080512);
    cin >> n;
    rep(i, 1, n) p[i] = i;
    rep(i, 1, n) rep(j, 1, n) cin >> mp[i][j];
    solve();
    cout <<(int) res;
    return ~~(0 ^ _ ^ 0);
}
