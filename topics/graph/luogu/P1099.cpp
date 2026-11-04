#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define il inline

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
        else if(flg==1)putchar('endl');
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

const int N = 3020;
int e , n , s , head[N] , vt[N<<1] , val[N<<1] , nxt[N<<1] , a[N] , f[N] , dis[N];
bool flag[N];

il void add(int u,int v,int c){
    nxt[++e]=head[u];
    head[u]=e;
    vt[e]=v;
    val[e]=c;
}

il void dfs(int u ,int fa) {
    for(int ed = head[u] , v; v = vt[ed],ed; ed = nxt[ed]) {
        if(v!=fa) {
            fa[v]=u;
            dis[v]=dis[u]+val[ed];
            dfs(v,u);
        }
    }
}

il void dfs1(int u,int fa,int id) {
    for (int e=head[u] , v ;v=vt[e],e;e=nxt[e]){
        if (v != fa&&!f[v]){
            a[id] = max(a[id],dis[v]-dis[u]);
            dfs1(v,u,id);
        }
    }
    
}

int x , y ,z;
int main() {
    read(n,s);
    for(int i = 1; i< n; ++i) {
        read(x,y,z);
        add(x,y,z);
        add(y,x,z);
    }
    dfs(1,0);
    int l = 0, r = 0;
    for(int i = 1; i<=n; ++i) 
        if(dis[i] > dis[l]) l = i;
    for(int i = 1; i<=n; ++i) dis[i] = 0;    
    dfs(l,0);
    for (int i=1; i<=n; i++)
        if (dis[i]>dis[r]) r=i;
    f[l] = 0;
    for (int i=r; i; i=f[i])
        f[i] = 1;
    for(int i = r;i;i=f[i])
        dfs1(i,0,i);
    int res = 0; 
    int minn = INT_MAX;
    for(int i = r; i; i=f[i]){
        for(int j = i;j;j=f[i]) {
            if(dis[i] - dis[j] > s) break;
            res = max(dis[j],dis[r]-dis[i]);
            for(int k = i; k!= f[j];k=f[k])
                res = max(res,a[k]);
            minn = min(minn,res);
        }
    }
    print(minn);
    return 0;
}
