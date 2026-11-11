//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("Ofast")


#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define re register
#define il inline
#define N 2200
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

ll n, m, k;
bool dp[N][N][2];
bool c[N], d[N];
ll a[N], b[N];
ll sum1[N], sum2[N];

il void fre(){
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
}
int t;

il void sol() {
    cin >> n >> m >> k;
    rep(i, 1, n) {
        cin >> a[i] >> c[i];
        sum1[i] = sum1[i - 1] + a[i];
    }
    rep(i, 1, m) {
        cin >> b[i] >> d[i];
        sum2[i] = sum2[i - 1] + b[i];
    }
    if(k == 0) {
        cout << 0 << endl;
        return ;
    }
    ll x = min(n, k), y = min(m, k);
    rep(i, 0, x) {
        rep(j, 0, y) {
            dp[i][j][0] = 0;
            dp[i][j][1] = 0;
        }
    }
    dp[1][0][0] = 1;
    dp[0][1][1] = 1;
    rep(i, 0, x) {
        rep(j, 0, min(y, k - i)) {
            if (i + j == k) continue;
            if (dp[i][j][0]) {
                if(j < m) dp[i][j + 1][1] = 1;
                if (i < n && c[i] == 0) dp[i + 1][j][0] = 1;
            }
            if (dp[i][j][1]) {
                if (i < n) dp[i + 1][j][0] = 1;
                if (j < m && d[j] == 0) dp[i][j + 1][1] = 1;
            }
        }
    }
    ll res = -INF;
    bool flag = 0;
    rep(i, max(0LL, k - m), min(n, k))  {
        int j = k - i;
        if (dp[i][j][0] || dp[i][j][1]) {
            flag = true;
            res = max(res, sum1[i] + sum2[j]);
        }
    }
    if (!flag) cout << "IMPOSSIBLE" << endl;
    else cout << res << endl;
}

int main() {
    //freOI(Name);
    //fre();
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);cout.tie(nullptr);
    cin >> t;
    while(t--) sol();
    return ~~(0 ^ _ ^ 0);
}