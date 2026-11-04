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

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; ++i) read(a[i]);
    for (int i = 0; i < m; ++i) read(b[i]);
    sort(b.begin(), b.end());
    vector<pair<int, int>> boxes(n);
    for (int i = 0; i < n; ++i) boxes[i] = {a[i], a[i]};
    sort(boxes.rbegin(), boxes.rend());
    priority_queue<int, vector<int>, greater<int>> pq;
    ll res = 0;
    int idx = 0;
    for (int i = 0; i < m; ++i) {
        while (idx < n && boxes[idx].first >= b[i]) {
            pq.push(boxes[idx].second);
            ++idx;
        }
        if (pq.empty()) {
            cout << -1 << endl;
            return 0;
        }
        res += pq.top();
        pq.pop();
    }
    print(res,1);
    return 0;
}
