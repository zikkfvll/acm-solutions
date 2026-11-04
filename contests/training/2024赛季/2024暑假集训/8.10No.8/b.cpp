//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")


#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define re register
#define il inline
const int MOD = 1e9 + 7 , N = 1000010 , M = 11;
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

int n;
ll dp[N][M];
il void fre(){
    freopen(".in", "r", stdin); 
    freopen(".out", "w", stdout);
}

signed main() {
    // freOI("sos");
    //fre();
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);cout.tie(nullptr);
    read(n);
    
    if(n < 9) {print(0, 1); return ~~(0 ^ _ ^ 0);}
    else if(n == 9) {print(1, 1); return ~~(0 ^ _ ^ 0);}
    else{
        dp[0][0] = 1;
        rep(i, 0, n - 1) {
            rep(j, 0, 11 - 1) {
                if(j == 10) dp[i + 1][j] = (dp[i + 1][j] + 26 * dp[i][j]) % MOD;
                else if(j == 9) dp[i + 1][j + 1] = (dp[i + 1][j + 1] + 26 * dp[i][j]) % MOD;
                else if(j == 1 || j == 4 || j == 7) {
                    dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
                    dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % MOD;
                    dp[i + 1][j - 1] = (dp[i + 1][j - 1] + 24 * dp[i][j]) % MOD;
                }
                else {
                    dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % MOD;
                    dp[i + 1][(j / 3) * 3] = (dp[i + 1][(j / 3) * 3] + 25 * dp[i][j]) % MOD;
                }
            }
        }
        print((dp[n][9] + dp[n][10]) % MOD, 1);
        return 0;
    }
    return ~~(0 ^ _ ^ 0);
}
