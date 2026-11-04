//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("Ofast")


#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define re register
#define il inline
#define N 50005
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

int n, m;
map<int,int> id;
int st[N][30];

il void St_init(){
	for(int j = 1; (1 << j) <= n; ++j) 
        for(int i = 1; i + (1 << j) - 1 <= n;++i)
		    st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}

il int query(int l, int r) {
    int k;
	for(k = 0; 1 << (k + 1) <= (r - l + 1); ++k);
	return max(st[l][k], st[r - (1 << k) + 1][k]);
}

il void fre(){
    freopen("C://Users//y//Downloads//.in", "r", stdin); 
    freopen("C://Users//y//Downloads//a.out", "w", stdout);
}

int main() {
    //freOI(Name);
    //fre();
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);cout.tie(nullptr);
    read(n);
    rep(i, 1, n) {
        int y;
        read(y, st[i][0]);
        id[y] = i;
    }
    read(m);
    St_init();
    while(m--) {
        int x, y;
        read(y, x);
        if(y >= x) {
            cout << "false" << endl;
            continue;
        }
        bool f1 = id.count(x), f2 = id.count(y), flag;
		if(!f1 && !f2){
			cout << "maybe" << endl;
			continue;
		}
		int kx, ky;
        map<int,int>::iterator itx, ity;
        itx = id.lower_bound(x);
        ity = id.lower_bound(y);
        if(ity == id.end()) {
            cout << "maybe" << endl;
            continue;
        }
        ky = ity -> second;
        if(itx == id.end()) kx = id.size() + 1;
        else kx = itx -> second;
        if(!f2) ky--;
        int ans;
        if(ky + 1 <= kx - 1) ans = query(ky + 1, kx - 1);
        else ans = 0;
        if(!f2) flag = ans < st[kx][0];
        else if(!f1) flag = st[ky][0] > ans;
        else flag = st[ky][0] >= st[kx][0] && st[kx][0] > ans;
        if(f1 && f2 && ky - kx == y - x) {
            if(flag) cout << "true" << endl;
            else cout << "false" << endl;
        }
        else {
            if(flag) cout << "maybe" << endl;
            else cout << "false" << endl;
        }
    }
    return ~~(0 ^ _ ^ 0);
}
