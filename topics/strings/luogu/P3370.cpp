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

const int B = 233;
struct point {
    ull x, y, z, k;
}a[N];
char s[N];
int n, res = 1;
const int MOD1 = 1817;
const int MOD2 = 2751;
const int MOD3 = 3437;
const int MOD4 = 3491;
il void fre(){
    freopen("C://Users//y//Downloads//.in", "r", stdin); 
    freopen("C://Users//y//Downloads//a.out", "w", stdout);
}

il ull hash1(char s[]) {
    int len = strlen(s);
    ull res = 0;
    for(int i = 0; i < len; ++i) 
        res = (1LL * res * B + s[i]) % MOD1;
    return res;
}

il ull hash2(char s[]) {
    int len = strlen(s);
    ull res = 0;
    for(int i = 0; i < len; ++i) 
        res = (1LL * res * B + s[i]) % MOD2;
    return res;
}

il ull hash3(char s[]) {
    int len = strlen(s);
    ull res = 0;
    for(int i = 0; i < len; ++i) 
        res = (1LL * res * B + s[i]) % MOD3;
    return res;
}

il ull hash4(char s[]) {
    int len = strlen(s);
    ull res = 0;
    for(int i = 0; i < len; ++i) 
        res = (1LL * res * B + s[i]) % MOD4;
    return res;
}

il bool cmp(point a, point b) {
    if(a.x != b.x) return a.x < b.x;
    if(a.y != b.y) return a.y < b.y;
    if(a.z != b.z) return a.z < b.z;
    return a.k < b.k;
}

int main() {
    //freOI(Name);
    //fre();
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);cout.tie(nullptr);
    read(n);
    rep(i, 1, n) {
        cin >> s;
        a[i].x = hash1(s);
        a[i].y = hash2(s);
        a[i].z = hash3(s);
        a[i].k = hash4(s);
    }
    sort(a + 1, a + n + 1, cmp);
    rep(i, 2, n) 
        if(a[i].x != a[i - 1].x || a[i].y != a[i - 1].y || a[i].z != a[i - 1].z || a[i].k != a[i - 1].k) res++;
    print(res, 1);
    return ~~(0 ^ _ ^ 0);
}
