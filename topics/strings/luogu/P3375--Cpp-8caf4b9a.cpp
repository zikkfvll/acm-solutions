#include <bits/stdc++.h>
using namespace std;
string s, t;
int len1, len2;
int nxt1[1000005], nxt2[1000005];

template<typename T>
inline void read(T &ans){
    char ch=getcha r();int f=1;ans=0;
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
namespace IO{
    inline void GetNext() {
        nxt1[0] = 0;
        int i = 1, length = 0;
        while (i < len2) {
            if (t[i] == t[length]) nxt1[i++] = ++length;
            else {
                if (length > 0) length = nxt1[length - 1];
                else nxt1[i++] = length;
            }
        }
    }

    inline void Kmp() {
        int i = 0, j = 0;
        nxt2[0] = -1;
        for (int i = 1; i < len2; i++) nxt2[i] = nxt1[i - 1];
        while (i < len1) {
            if (j == len2 - 1 && s[i] == t[j]) {
                cout << (i - j + 1) << endl;
                j = nxt2[j];
                if (j == -1) ++j;
            }
            if (s[i] == t[j]) ++j, ++i;
            else {
                j = nxt2[j];
                if (j == -1) ++i, ++j;
            }
        }
    }

    inline void init() {
        cin >> s >> t;
        len1 = s.length();
        len2 = t.length();
    }

    inline void work() {
        init();
        GetNext();
        Kmp();
        for (int i = 0; i < len2; i++) cout << nxt1[i] << " ";
    }
}


int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    IO::work();
    return 0;
}