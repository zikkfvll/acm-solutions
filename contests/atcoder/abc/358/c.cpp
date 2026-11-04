//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")


#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define re register
#define il inline
#define N 1000010
#define mOD 998244353
#define esp 1e-8
#define INF INT_MAX-10
#define rep(x, y, z) for(int x = (y); x <= (z); ++x)
#define per(x, y, z) for(int x = (y); x >= (z); --x)
#define debug(format...) fprintf(stderr, format)
#define freOI(name) do {freopen(name".in", "r", stdin); freopen(name".out", "w", stdout);} while(false)
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

bool coversAllFlavors(const vector<string>& stands, int combo, int m) {
    vector<bool> covered(m, false);
    for (int i = 0; i < stands.size(); ++i) {
        if (combo & (1 << i)) {
            for (int j = 0; j < m; ++j) {
                if (stands[i][j] == 'o') covered[j] = 1;
            }
        }
    }
    for (int j = 0; j < m; ++j) {
        if (!covered[j]) return false;
    }
    return 1;
}

int main() {
    //freOI(name);
    //fre();
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<string> stands(n);
    for (int i = 0; i < n; ++i)  cin >> stands[i];
    int res = INF;
    for (int combo = 1; combo < (1 << n); ++combo) {
        if (coversAllFlavors(stands, combo, m)) {
            int count = __builtin_popcount(combo);
            if (count < res) {
                res = count;
            }
        }
    }
    print(res,1);
    return 0;
}