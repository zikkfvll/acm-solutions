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
string sol(string s) {
    size_t firstBarPos = s.find('|');
    size_t secondBarPos = s.find('|', firstBarPos + 1);
    s.erase(firstBarPos, secondBarPos - firstBarPos + 1);
    return s;
}

int main() {
    string S;
    cin >> S;
    string result = sol(S);
    cout << result << endl;
    return 0;
}