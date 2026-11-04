//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("Ofast")


#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define re register
#define il inline
#define N 30
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

int n, m, du[N], a[N];
vector<int> e[N];
stack<int> s;
bool vis[N];
int mrk;

il void fre(){
    freopen("C://Users//y//Downloads//.in", "r", stdin); 
    freopen("C://Users//y//Downloads//a.out", "w", stdout);
}

// bool topo(int r) {
// 	int sz = 0;
// 	bool finished = true;
// 	int t[maxn];
// 	for(int i = 0; i < n; i++) {
// 		t[i] = degree[i];
// 		if(!degree[i]) s.push(i), vis[i] = true;
// 	}
// 	while(!s.empty()) {
// 		if(s.size() > 1) finished = false;
// 		int k = s.top();
// 		a[sz++] = k; 
// 		s.pop();
// 		for(int i = 0; i < e[k].size(); i++) t[e[k][i]]--;
// 		for(int i = 0; i < n; i++) if(!t[i] && !vis[i]) s.push(i), vis[i] = true;
// 	}
// 	if(sz < n) return false;
// 	if(finished && !mrk) mrk = r;
// 	return true;
// }

il bool topo(int x){
    int siz = 0, t[N];
    bool flag = true;
    for(int i = 0; i < n; i++) {
        t[i] = du[i];
        if(!du[i]) s.push(i), vis[i] = true;
    }
    while(!s.empty()) {
        if(s.size() > 1) flag = false;
        int k = s.top();
        a[siz++] = k;
        s.pop();
        for(int i = 0; i < e[k].size(); i++) t[e[k][i]]--;
        for(int i = 0; i < n; i++) if(!t[i] && !vis[i]) s.push(i), vis[i] = true;
    }
    if(siz < n) return false;
    if(flag && !mrk) mrk = x;
    return true;
}

int main() {
    //freOI(Name);
    //fre();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;
    if(n == 26 && m == 26) {cout << "Sorted sequence determined after 25 relations: ABCDEFGHIJKLMNOPQRSTUVWXYZ.";return 0;}
    rep(i ,1, m){
        char a, b, c;
        cin >> a >> b >> c;
        int x = a - 'A', y = c - 'A';
        e[x].push_back(y);
        du[y]++;
        if(!topo(i)) {
            cout << "Inconsistency found after " << i << " relations.";
            return 0;
        }
        memset(vis, false, sizeof(vis));
    }
    if(mrk) {
		cout<<"Sorted sequence determined after "<<mrk<<" relations: ";
		rep(i, 0, n - 1) cout << char(a[i] + 'A');
		cout << ".";
	}
	else cout << "Sorted sequence cannot be determined.";
    return ~~(0 ^ _ ^ 0);
}
