//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")


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

il void fre(){
    freopen(".in", "r", stdin); 
    freopen(".out", "w", stdout);
}

bool sol(const vector<pair<int, int>>& cards, unordered_set<int>& seen) {
    int st = 0;
    for (int i = 1; i < cards.size(); ++i) {
        st = st * 10 + cards[i].first;
        st = st * 10 + cards[i].second;
    }
    if (seen.count(st))  return false;
    seen.insert(st);
    for (int i = 1; i < cards.size(); ++i) {
        for (int j = i + 1; j <= cards.size(); ++j) {
            if (cards[i].first == cards[j].first || cards[i].second == cards[j].second) {
                vector<pair<int, int>> now;
                for (int k = 1; k <= cards.size(); ++k) if (k != i && k != j)  now.push_back(cards[k]);
                if (!sol(now, seen)) return true; 
            }
        }
    }
    return false;
}

int main() {
    //freOI(Name);
    //fre();
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);cout.tie(nullptr);
    read(n);
    vector<pair<int, int>> cards(n + 1);
    rep(i, 1, n) read(cards[i].first, cards[i].second);
    unordered_set<int> seen;
    if (sol(cards, seen)) printf("Takahashi" );
    else printf("Aoki");
    return 0;
}
