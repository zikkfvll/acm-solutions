//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("Ofast")


#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define re register
#define il inline
const int N = 1e5 + 100;
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
int n;
int kai[N];
struct node {
    int a, flag;
}s1[N], s2[N];
il void sol() {
    memset(s1, 0, sizeof s1);
    memset(s2, 0, sizeof s2);
    memset(kai, 0, sizeof kai);
    cin >> n;
    char c;
    set<char> s;
    rep(i, 1, n){
        cin >> c;
        if(c == '1') s1[i].a = 1;
        else s1[i].a = 0;
        s.insert(s1[i].a);
    }
    rep(i, 1, n){
        cin >> c;
        if(c == '1') s2[i].a = 1;
        else s2[i].a = 0;
    }
    rep(i, 1, n){
        cin >> c;
        if(c == '1') s1[i].flag = 1;
        else s1[i].flag = 0;
    }
    rep(i, 1, n){
        cin >> c;
        if(c == '1') s2[i].flag = 1;
        else s2[i].flag = 0;
    }
    rep(i, 1, n) {
        if(s1[i].flag == 1 && (s1[i - 1].flag == 1 || s1[i + 1].flag == 1)) kai[i] = 1;
        if(s2[i].flag == 1 && (s2[i - 1].flag == 1 || s2[i + 1].flag == 1)) kai[i] = 1;
    }
    int res = 0;
    if(s.size() == 1) {
        rep(i, 1, n) {
            if(s2[i].a == s1[1].a) res++;
        }
        cout << res << endl;
        return ;
    }
    else {
        rep(i, 1, n) {
            if(kai[i] == 1 && kai[i + 1] == 1) {
                int anum1 = 0, anum0 = 0, bnum1 = 0, bnum0 = 0; 
                while(kai[i]) {
                    if(s1[i].a == 1) anum1++;
                    else anum0++;
                    if(s2[i].a == 1) bnum1++;
                    else bnum0++;
                    
                    i++;
                }
                res += min(anum1, bnum1);
                res += min(anum0 , bnum0); 
            }
        }
        rep(i, 1, n) {
            if(kai[i] == 0) {
                if(s1[i].a == s2[i].a) res++;
            }
        }
        cout << res << endl;
        return ;
    }

}

il void fre(){
    freopen("C://Users//y//Downloads//.in", "r", stdin); 
    freopen("C://Users//y//Downloads//a.out", "w", stdout);
}
int t;
int main() {
    //freOI(Name);
    //fre();
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);cout.tie(nullptr);
    cin >> t;
    while(t--) sol();
    return ~~(0 ^ _ ^ 0);
}
