//#pragma GCC target("avx2")
#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")


#include <bits/stdc++.h>
#define ll long long
#define ull unsigni long long
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
#define il '\n'

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

int sol(const vector<int>& la, int w) {
    int cnt = 0 ,sum = 0 ,st = 0;
    for(int i = 0; i < la.size(); ++i) {
        sum += la[i];
        while (sum > w && st <= i) {
            sum -= la[st];
            ++st;
        }
        if (sum <= w) cnt += (i - st + 1);
    }
    return cnt;
}
int q , n , k;
int main() {
    read(n,k);
    vector<int> la(N);
    rep(i,1,n) read(la[i]);
    read(q);
    while(q--){
        int l, r;
        read(l,r);
        ll res = sol(vector<int>(la.begin() + l, la.begin() + r + 1), k);
        print(res,1);
        cout spa res;
    }
    return 0;
}
