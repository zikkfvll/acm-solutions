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

int n;
ll k;

il void fre(){
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
}
int T;
int lt[N];
int res;

il void sol() {
    res = 0;
    memset(lt, 0, sizeof(lt));
    read(n, k);
    rep(i, 1, n) {
        int x;
        read(x);
        if(x <= k) {
            res = max(res, i - lt[x] - 1);
            lt[x] = i;
        }
    }
    if(k >= n) {
        print(n, 1);
        return ;
    }
    rep(i, 0, k) res = max(res, n - lt[i]);
    print(res, 1);

}

int main() {
    //freOI(Name);
    //fre();
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);cout.tie(nullptr);
    read(T);
    while(T--) sol();
    return ~~(0 ^ _ ^ 0);
}
