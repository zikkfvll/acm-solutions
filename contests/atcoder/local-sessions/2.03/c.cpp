#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define il inline
const int N=1e5+50;
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
int n;
int a[N];
int main() {
    //fre();
    read(n);
    for(int i=1;i<=n;i++) read(a[i]);
    ll sum = 0 , t = 0;
    for(int i=1;i<=n;i++){
        sum += a[i];
        if(sum <= 0) t = -sum;
    }
    //print(t);
    ll res = 0;
    for(int i=1;i<=n;i++){
        res += (t + a[i]);
    }
    print(res);
    return 0;
}
