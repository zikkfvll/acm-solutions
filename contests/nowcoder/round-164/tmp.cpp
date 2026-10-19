//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define re register
#define il inline
#define N 220000
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
        T x=ret;
        int top=0;
        bool f=(ret<0);

        if(ret<0) x=-x;

        do{
            sta[top++]=x%10;
            x/=10;
        }while(x);

        if(f) putchar('-');

        while(top)
            putchar(sta[--top]+48);

        if(flg==0) putchar(' ');
        else if(flg==1) putchar('\n');
    }

    template<typename T>
    inline void read(T &ans){
        char ch=getchar();
        int f=1;
        ans=0;

        for(;!isdigit(ch);ch=getchar())
            if(ch=='-') f=-1;

        for(;isdigit(ch);ch=getchar())
            ans=(ans<<3)+(ans<<1)+(ch&15);

        ans*=f;
    }

    template<typename T,typename ...Args>
    inline void read(T &tmp,Args &...tmps){
        read(tmp);
        read(tmps...);
    }
}

using namespace std;
using namespace fastOI;

ll x, y, s, m, k;
int n;

ll a[N];
int b[N];

ll box[N], nobox[N];
ll sum0[N], sum1[N];

int cnt0, cnt1;
ll res;

int main() {

    read(x, y, s, m, k);
    read(n);

    rep(i, 1, n)
        read(a[i]);

    rep(i, 1, n) {
        read(b[i]);

        if(b[i] == 1)
            box[++cnt1] = a[i];
        else
            nobox[++cnt0] = a[i];
    }

    // 每一类都优先选择报价高的顾客
    sort(box + 1, box + cnt1 + 1, greater<ll>());
    sort(nobox + 1, nobox + cnt0 + 1, greater<ll>());

    // 前缀和
    rep(i, 1, cnt0)
        sum0[i] = sum0[i - 1] + nobox[i];

    rep(i, 1, cnt1)
        sum1[i] = sum1[i - 1] + box[i];

    // 一个不需要篮子的顾客的进货成本
    ll cost0 = k * x;

    // 一个需要篮子的顾客的进货成本
    ll cost1 = k * x + y;

    // 桃子最多可以服务多少名顾客
    ll maxPeople = m / k;

    // 枚举接多少个需要篮子的顾客
    rep(i, 0, cnt1) {

        // 需要的资金
        ll need = 1LL * i * cost1;

        // 钱不够
        if(need > s)
            break;

        // 桃子不够
        if(i > maxPeople)
            break;

        // 剩余资金
        ll remainMoney = s - need;

        // 剩余桃子还能服务多少人
        ll remainPeople = maxPeople - i;

        // 最多接多少个不需要篮子的顾客
        ll j = min({
            (ll)cnt0,
            remainPeople,
            remainMoney / cost0
        });

        // 当前营业额
        res = max(res, sum1[i] + sum0[j]);
    }

    print(res, 1);

    return ~~(0 ^ _ ^ 0);
}