//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("Ofast")


#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define re register
#define il inline
#define N 330000
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
    inline void read(T &res){
        char ch=getchar();int f=1;res=0;
        for(;!isdigit(ch);ch=getchar()) ch=='-'?f=-1:f=1;
        for(;isdigit(ch);ch=getchar()) res=(res<<3)+(res<<1)+(ch&15);
        res*=f;
        return;
    }
    template<typename T,typename ...Args>
    inline void read(T &tmp,Args &...tmps){read(tmp);read(tmps...);}
}

using namespace std;
using namespace fastOI;

int n, k;
int cnt;
int a[15];
int id[N];
int res[N][10];

bool cmp(int x, int y) {
    for(int i = 0; i < n; i++) {
        if(res[x][i] != res[y][i])
            return res[x][i] < res[y][i];
    }

    return false;
}

il void dfs(int pos, int sum) {
    if(pos == n + 1) {
        a[1] = k - sum;
        rep(i, 1, n) res[cnt][i - 1] = a[i];
        id[cnt] = cnt;
        cnt++;
        return ;
    }
    for(int i = 0; sum + pos * i <= k; i++) {
        a[pos] = i;
        dfs(pos + 1, sum + pos * i);
    }
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
    cin >> n >> k;
    if(n == 1) cout << k << endl;
    else {
        dfs(2, 0);
        sort(id, id + cnt, cmp);
        rep(i, 0, cnt - 1) {
            int x = id[i];
            rep(j, 0, n - 1) cout << res[x][j] << " ";
            cout << endl;
        }
    }
    return ~~(0 ^ _ ^ 0);
}
