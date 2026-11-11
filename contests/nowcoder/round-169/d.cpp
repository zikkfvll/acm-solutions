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

il void fre(){
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
}

int n, m;
char a[N];
int id[N];
int x1, yy, x2, y2;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int sx, sy;

il int pos(int x, int y) {
    return (x - 1) * m + y;
}

int main() {
    cin >> n >> m;
    rep(i, 1, n) rep(j, 1, m) cin >> a[pos(i, j)];
    cin >> x1 >> yy >> x2 >> y2;
    rep(i, 1, n) {
        rep(j, 1, m) {
            if(a[pos(i, j)] == '*') {
                sx = i;
                sy = j;
                break;
            }
        }
        if(sx != 0) break;
    }
    int px = sx, py = sy;
    int x = sx, y = sy + 1;
    int cnt = 1;
    id[pos(sx, sy)] = 0;
    while(x != sx || y != sy) {
        id[pos(x, y)] = cnt++;
        rep(k, 0, 3) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if(a[pos(nx, ny)] != '*') continue;
            if(nx == px && ny == py) continue;
            px = x, py = y, x = nx, y = ny;
            break;
        }
    }
    int aa = id[pos(x1, yy)];
    int bb = id[pos(x2, y2)];
    cout << (bb - aa + cnt) % cnt << endl;
    return ~~(0 ^ _ ^ 0);
}
