#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define il inline
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)

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


const int N=1e6+5;
int n,c[26];
char s[N];
int main()
{
	scanf("%s",s);
	while(s[n])++n;
	F(i,0,n)++c[s[i]-'a'];
	long long ans=0;
	F(i,0,26)F(j,i+1,26)ans+=(long long)c[i]*c[j];
	bool eq=false;
	F(i,0,26)eq|=c[i]>1;
	ans+=eq;
	printf("%lld\n",ans);
	return 0;
}
