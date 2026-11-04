// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long long nxt[1000005] , n;
char s[1000005];
int T;
long long res;

template <class T>
inline void print(T ret, long long flg = 0)
{
    static long long sta[35];
    T x = ret;
    long long top = 0;
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

template <typename T>
inline void read(T &ans)
{
    char ch = getchar();
    long long f = 1;
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

namespace IO
{
    inline void GetNext()
    {
        nxt[0] = strlen(s);
        int num =0;
        while (s[num] == s[num + 1] && num +1 < n) num++;
        nxt[1] = num;
        int p=1;
        for (int i = 2; i <= n; ++i)
        {
            if(i + nxt[i - p] < nxt[p] + p) nxt[i] = nxt[i - p];
            else{
                int now = nxt[p] + p-i;
                now = max(now, 0);
                while (s[now] == s[now + i] && now + i < n) now++;
                nxt[i] = now;
                p = i;
            }
        }
    }

    inline void crle(int x)
    {
        scanf("%s", s);
        n = strlen(s);
        for(int i = 0;i <= n;++i) nxt[i] = 0;
        GetNext();
        int res = 0;
        for(int i = 1;i < n;++i) if(nxt[i] == n - i) ++res;
        cout << "Case " << x << ": " << res << endl;
    }

    inline void work()
    {
        for(int i = 1;i <= T;++i) crle(i);
    }
}

int main() {
    // freopen("zoo.in", "r", stdin);
    // freopen("zoo.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    read(T);    
    IO::work();
    return 0;
}
