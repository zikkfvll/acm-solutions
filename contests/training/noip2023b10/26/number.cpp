//#pragma GCC optimize(2)
#include <bits/stdc++.h>
bool st;
using namespace std;
long long len , n , m , a[20], dp[20][20][20][2][2][2][2];

template <typename T>
inline void read(T &ans)
{
    char ch = getchar();
    int f = 1;
    ans = 0;
    for (; !isdigit(ch); ch = getchar())
        ch == '-' ? f = -1 : f = 1;
    for (; isdigit(ch); ch = getchar())
        ans = (ans << 3) + (ans << 1) + (ch & 15);
    ans *= f;
    return;
}
template <typename T, typename... Args>
inline void read(T &tmp, Args &...tmps)
{
    read(tmp);
    read(tmps...);
}

template <class T>
inline void print(T ret, int flg = 0)
{
    static int sta[35];
    T x = ret;
    int top = 0;
    bool f = (ret < 0);
    if (ret < 0)
        x = -x;
    do
    {
        sta[top++] = x % 10, x /= 10;
    } while (x);
    if (f)
        putchar('-');
    while (top)
        putchar(sta[--top] + 48);
    if (flg == 0)
        putchar(' ');
    else if (flg == 1)
        putchar('\n');
}

namespace work{
    inline long long dfs(long long pos, long long sum, long long last, bool fflag, bool flagg, bool lim, bool head) {
        if (lim && head) return 0;
        if(pos <= 0) return fflag;
        // if (pos > len) {
        //     if (sum == 3 && !(fflag && flagg)) return 1;
        //     else return 0;
        // }
        if (~dp[pos][sum][last][fflag][flagg][lim][head]) return dp[pos][sum][last][fflag][flagg][lim][head];
        long long tmp = (!flagg ? a[pos] : 9);
        long long tmp2 = 0;
        for (int i = 0; i <= tmp; ++i) {
            tmp2 += dfs(pos - 1,i,sum,fflag||(i == last &&i == sum),flagg||(i < tmp),lim || (i==4),head||(i==8));
            //if(pos == len&&i==0) continue;
        }
        return dp[pos][sum][last][fflag][flagg][lim][head] = tmp2;
    }

    inline void init() {
        read(n,m);
    }

    inline long long solve( long long x) {
        if(x<1e10) return 0;
        int i;
        memset(dp, -1, sizeof(dp));
        for(i=0;x;x/=10) a[++i] = x%10;
        long long res =0;
        for(int j=1;j<=a[i];++j) res += dfs(10,j,0,0,j<a[i],j==4,j==8);
        return res;
    }

    inline void OI(){
        init();
        print(solve(m) - solve(n-1),1);
        }
}

int main() {
    //freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    work::OI();
    //bool ed;
    //cerr << (double)(&ed-&st) / 1024 / 1024 << " MB" << endl;
    return 0;
}
