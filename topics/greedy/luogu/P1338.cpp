#include <bits/stdc++.h>
using namespace std;
long long n, m, a[50005];
long long last , first = 1;

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

int main() {
    read(n, m);
    last = n;
    for (int i = 1; i <= n; i++) {
        long long t = ((n - i - 1) * (n - i)) / 2;
        if (t >= m) a[first++] = i;
        else {
            a[last--] = i; 
            m -= (last - first + 1);
        }
    }
    for (int i = 1; i <= n; i++) print(a[i] , 0);
    return 0;
}