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

string s, a, b;
int n, l, block;
bool flag1, flag2;

il void fre(){
    freopen("C://Users//y//Downloads//.in", "r", stdin); 
    freopen("C://Users//y//Downloads//a.out", "w", stdout);
}

il void init() {
    cin >> n >> s;
    block = n / 2;
    a = s.substr(0, block);
    b = s.substr(n - block, n);
}

il void sol() {
    for (int i = block; i <= n - 1 && l < block; ++i) if (s[i] == a[l]) l++;
    if(l == block) flag1 = 1;
    l = 0;
    for (int i = 0; i <= n - block - 1 && l < block; ++i) if (s[i] == b[l]) l++;
    if(l == block) flag2 = 1;
}

int main() {
    //freOI(Name);
    //fre();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    init(); sol();
    if(n % 2 == 0) {cout << "NOT POSSIBLE" << endl; return ~~(0 ^ _ ^ 0);}
    if(!flag1 && !flag2) cout << "NOT POSSIBLE" << endl;
    else {
        if(flag1 && flag2 && a != b) cout << "NOT UNIQUE" << endl;
        else {
            if(flag1) cout << a << endl;
            else cout << b << endl;
        }
    }
    return ~~(0 ^ _ ^ 0);
}
