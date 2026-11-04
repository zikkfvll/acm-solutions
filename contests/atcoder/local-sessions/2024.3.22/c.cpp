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
    template<typename T,typename ...args>
    inline void read(T &tmp,args &...tmps){read(tmp);read(tmps...);}
}
using namespace std;
using namespace fastOI;

int n, k;
int main() {
    //fre();
	read(n,k);
	vector<int> a(n);
	for (int i = 0; i < n; ++i) read(a[i]);
    long long tt = (long long)k * (k + 1) / 2;
    long long aa = 0;
	vector<bool> add(k + 1, false);
	for (int i = 0; i < n; ++i) {
		if (a[i] <= k && !add[a[i]]) {
			aa += a[i];
			add[a[i]] = true;
		}
	}
    long long sum = tt - aa;
	print(sum,0);
    return 0;
}
