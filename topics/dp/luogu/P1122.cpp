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

const int N = 16060;
vector<int>edge[N];
int n , a[N];

il int dfs(int v , int f) {
    int res = a[v];
    for(int i = 0; i< edge[v].size(); i++)
        if(edge[v][i] != f) res += max(0,dfs(edge[v][i],v));
    return res;
}

int main() {
    //fre();
    read(n);
    for(int i = 1; i<=n;i++) read(w+i);
    for(int i = 1; i <= n- 1; --i) {
        int x ,y;
        read(x,y);
        edge[x].push_back(y);
        edge[y].push_back(x);
    }    
    print(dfs(1,0),1);
    return 0;
}
