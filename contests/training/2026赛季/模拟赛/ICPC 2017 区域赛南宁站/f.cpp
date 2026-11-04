//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("Ofast")


#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define re register
#define il inline
#define N 110
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

int t;
int n[N], a[N], b[N];
int ln, la, lb;

il void mul() {
    memset(b, 0, sizeof b);
    lb = la;
    rep(i, 1, la) {
        b[i] += a[i] * 2;
        if(b[i] >= 10) {
            b[i + 1] += b[i] / 10;
            b[i] %= 10;
        }
    }
    if(b[la + 1]) lb++;
}

il bool ck() {
    if(lb != ln) return lb < ln;
    per(i, lb, 1) {
        if(b[i] != n[i]) return b[i] < n[i];
    }
    return true;
}

il void init(string s) {
    memset(a, 0, sizeof a);
    memset(n, 0, sizeof n);
    la = 1, lb = 1;
    a[1] = 1, b[1] = 1;
    ln = s.size();
    rep(i, 0, ln - 1) n[ln - i] = s[i] - '0';
}

il void sol() {
    string s;
    cin >> s;
    init(s);
    while(true) {
        mul();
        if(ck()) {
            la = lb;
            rep(i, 1, la) a[i] = b[i];
        }
        else break;
    }
    per(i, la, 1) cout << a[i];
    cout << endl;
}

il void fre(){
    freopen("C://Users//y//Downloads//.in", "r", stdin); 
    freopen("C://Users//y//Downloads//a.out", "w", stdout);
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
