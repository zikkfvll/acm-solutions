#include <bits/stdc++.h>
using namespace std;
int n, res;
int a[5005];
long long fac[14] = {0, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 6227020800};

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

inline bool check(int pos) {
    for (int i = 1; i <= (1 << (n - pos)); ++i) if (a[(i - 1) * (1 << pos) + 1] + (1 << (pos - 1)) != a[(i - 1) * (1 << pos) + (1 << (pos - 1)) + 1]) return false;
    return true;
}

inline void swap(int aa, int b, int c) {
    for (int i = 1; i <= c; i++) swap(a[i + aa - 1], a[i + b - 1]);
}

inline void dfs(int pos, int sum) {
    if (pos && !check(pos)) return;
    if (pos == n){res += fac[sum]; return;}
    // for(int i = 1; i<=(1<<(n-pos));i++){
    //     if(a[i*(1 << pos) + 1] != a[(i-1)*(1<<pos)+1]+(1 << pos)){
    //         swap(i*(1 << pos) + 1,(i-1)*(1<<pos)+1,pos);
    //         dfs(pos + 1,sum + i);
    //         swap(i*(1 << pos) + 1,(i-1)*(1<<pos)+1,pos);
    //     }
    // }
    dfs(pos + 1, sum);
    int fl[10], cnt = 0;
    for (int i = 1; i <= (1 << (n - pos)); i += 2)
    {
        if (a[i * (1 << pos) + 1] != a[(i - 1) * (1 << pos) + 1] + (1 << pos))
        {
            if (cnt == 4) break;
            fl[++cnt] = i;
            fl[++cnt] = i + 1;
        }
    }
    //if(cnt == 4) return;
    if (!cnt) return;
    for (int i = 1; i <= cnt; ++i)
        for (int j = i + 1; j <= cnt; ++j) {
            swap((1 << pos) * (fl[i] - 1) + 1, (1 << pos) * (fl[j] - 1) + 1, 1 << pos);
            dfs(pos + 1, sum + 1);
            swap((1 << pos) * (fl[i] - 1) + 1, (1 << pos) * (fl[j] - 1) + 1, 1 << pos);
        }
}

inline void init() {
    read(n);
    for (int i = 1; i <= (1 << n); ++i) cin >> a[i];
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    init();
    dfs(0, 0);
    print(res , 1);
    return 0;
}