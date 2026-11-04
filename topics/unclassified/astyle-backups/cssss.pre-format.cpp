//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("Ofast")


#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define re register
#define il inline
#define N 3000005
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

int t, n, q;
int nex[N][65], idx , cnt[N];

int getnum(char x){
    if(x >= 'A' && x <= 'Z') return x - 'A';
    else if(x >= 'a' && x <= 'z') return x - 'a' + 26;
    else return x - '0' + 52;
} 

// struct Trie{
    il void insert(char *s, int l){
        int p = 0;
        for(int i = 0; i < l ; ++i) {
            int c = getnum(s[i]);
            if(!nex[p][c]) nex[p][c] = ++idx;
            p = nex[p][c];
            cnt[p]++;
        }
        return ;
    }

    il bool query(char *s, int l){
        int p = 0;
        for(int i = 0; i < l ; ++i) {
            int c = getnum(s[i]);
            if(!nex[p][c]) return 0;
            p = nex[p][c];
        }
        return cnt[p];
    }
// };

il void fre(){
    freopen("C://Users//y//Downloads//.in", "r", stdin); 
    freopen("C://Users//y//Downloads//a.out", "w", stdout);
}

int main() {
    //freOI(Name);
    //fre();
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);cout.tie(nullptr);
    cout << "debug 1" << endl;
    for(cin >> t; t; --t) {
        cout << "debug" << endl;
        // Trie tr;
        rep(i, 0, idx) rep(j, 0, 122) nex[i][j] = 0;
        rep(i, 0, idx) cnt[i] = 0;
        idx = 0;
        cin >> n >> q;
        rep(i, 1, n) {
            char s[N];
            cin >> s;
            insert(s, strlen(s));
        }
        rep(i, 1, q) {
            char s[N];
            cin >> s;
            cout << query(s, strlen(s)) << '\n';
        }
    }
    return ~~(0 ^ _ ^ 0);
}
