//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define re register
#define il inline
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
#define mid ((l+r)>>1)
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

const int N = 200010;
int sum[N << 5], ls[N << 5], rs[N << 5], num, n, m, q, cnt, a[N] ,b[N], T[N];

inline int build(int l, int r) {
    int rt = ++ cnt;
    sum[rt] = 0;
    if (l < r){
        ls[rt] = build(l, mid);
        rs[rt] = build(mid+1, r);
    }
    return rt;
}

// il int update(int pre,int l,int r,int loc) {
//     int p = ++num;
//     ls[p] = ls[pre],rs[p] = rs[pre],sum[p] = sum[pre] + 1;
//     if(l < r) {
//     	if(loc <= mid) ls[p] = update(ls[pre],l,mid,loc);
// 		else rs[p] = update(rs[pre],mid+1 , r , loc); 
// 	}
//     return p;
// }

inline int update(int pre, int l, int r, int x) {
    int p = ++ cnt;
    ls[p] = ls[pre]; rs[p] = rs[pre]; sum[p] = sum[pre]+1;
    if (l < r){
        if (x <= mid) ls[p] = update(ls[pre], l, mid, x);
        else rs[p] = update(rs[pre], mid+1, r, x);
    }
    return p;
}

il int query(int u,int v,int l ,int r , int k) {
    if(l >= r) return l;
    int p = sum[ls[v]] - sum[ls[u]];
    if(p >= k) return query(ls[u],ls[v],l,mid,k);
    else return query(rs[u],rs[v],mid+1,r,k-p);
    if(sum[ls[v]] - sum[rs[u]] >= k) return query(ls[u],ls[v],l,mid,k); 
}

int main() {
    //freOI(Name);
    //fre();
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);cout.tie(nullptr);
    read(n,q);
	//cin >> n >> q; 
    for(int i = 1; i <= n; i++) {
    	read(a[i]);
    	//cin >>a[i];
    	b[i] = a[i];
	}
	sort(b+1, b+1+n);
    m = unique(b+1, b+1+n)-b-1;
    T[0] = build(1, m);
    //cout <<endl;
    //for(int i =0;i <=n;++i) cout << b[i] << " " ;
   // cout << endl;
   // cout << T[0]<<endl;
    for(int i = 1 ;i <= n;++i) {
    	int tp = lower_bound(b+1,b+m+1,a[i]) - b;
    	T[i] = update(T[i-1] , 1, m ,tp);
	}
    // cout <<endl;
    // for(int i = 0 ;i <=n ;++i) cout << T[i] << " " ;
	// cout << endl << " m= " << m << endl;
    while(q--) {
		int x , y, z;
		read(x,y,z);
		int tp = query(T[x-1],T[y],1,m,z);
		print(b[tp],1);	
	}   
    return ~~(0 ^ _ ^ 0);
}
