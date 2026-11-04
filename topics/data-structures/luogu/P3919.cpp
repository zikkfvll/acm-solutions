#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define il inline
#define mid ((l+r) >> 1)
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

const int N = 1000005;
int root[N << 5], val[N << 5], ls[N << 5], rs[N << 5], num, n, m, a[N];

il void build(int &p,int l,int r) {
    if(!p) p = ++num;
    if(l == r) {
        val[p] = a[l];
        return;
    }
    build(ls[p],l,mid);
    build(rs[p],mid + 1,r);
}

il void update(int &p,int pre,int l,int r,int loc,int v) {
    p = ++num;
    ls[p] = ls[pre],rs[p] = rs[pre],val[p] = val[pre];
    if(l == r) {
        val[p] = v;
        return;
    }
    if(loc <= mid) update(ls[p], ls[pre], l, mid, loc, v);
	if(loc > mid) update(rs[p], rs[pre], mid+1, r, loc, v);
}

il int query(int p,int l ,int r , int q) {
    if(l == r) return val[p];
	if(q <= mid) return query(ls[p], l, mid, q);
	if(q > mid) return query(rs[p], mid+1, r, q);
}

int main() {
    //fre();
    read(n,m);
    for(int i = 1; i <= n; i++) read(a[i]);
    build(root[0],1,n);
    for(int i = 1; i <= m; i++) {
        int p, op, x, y;
        read(p,op);
        if(op == 1) {
            read(x,y);
            update(root[i], root[p], 1, n, x, y);
        }
        else {
            read(x);
            print(query(root[p], 1, n, x),1);
			root[i] = root[p];
        }
    }
    return 0;
}
