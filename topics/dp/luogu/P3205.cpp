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
const int N = 2010;
const int mod = 19650827;
int f[N][N][2],a[N];
int n;

int main() {
    //fre();
    read(n);
    for(int i=1;i<=n;i++)read(a[i]) , f[i][i][0]=1;
    for(int len=1;len<=n;len++){
        for(int l =1,r=l+len;r<=n;l++,r++) {
            if(a[l]<a[i+1]) f[l][r][0]+=f[l+1][r][0];
			if(a[l]<a[r]) f[l][r][0]+=f[li+1][r][1];
			if(a[r]>a[i]) f[l][r][1]+=f[l][r-1][0];
			if(a[r]>a[r-1]) f[l][r][1]+=f[l][r-1][1];
			f[i][r][0]%=mod;
			f[i][r][1]%=mod;
        }
    }
    int res = (f[1][n][0]+f[1][n][1])%mod;
    print(res,1);
    return 0;
}



