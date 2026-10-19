//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("Ofast")


#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define re register
#define il inline
#define N 1000010
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

ll v[110];
int cnt;
il void sgcd(ll n) {
    for(ll i = 2; i * i <= n; i++) {
        while(n % i == 0) {
            v[++cnt] = i;
            n /= i;
        }
    }
    if(n > 1) v[++cnt] = n;
}  
il void sol() {
    ll x, y;
    read(x, y);
    cnt = 0;
    memset(v, 0, sizeof(v));
    sgcd(x);
    sgcd(y);
    sort(v + 1, v + cnt + 1);
    ll g = 1;
    int i = 1;
    while (i <= cnt) {
        if (i < cnt && v[i] == v[i + 1]) {
            g *= v[i];
            i += 2;
        } 
        else i++;
    }
    cout << g spa x * y / g << endl;
}

il void fre(){
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
}

int main() {
    //freOI(Name);
    //fre();
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);cout.tie(nullptr);
    int T;
    read(T);
    while(T--) sol();
    return ~~(0 ^ _ ^ 0);
}
