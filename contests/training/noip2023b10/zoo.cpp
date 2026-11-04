// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long long nextn[1000005], num[1000005], n;
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
        for (int i = 2, j = 0; i <= n; ++i)
        {
            while (j && s[i] != s[j + 1])
                j = nextn[j];
            if (s[j + 1] == s[i])
                ++j;
            nextn[i] = j;
            num[i] = num[j] + 1;
        }
    }

    inline void GetNum()
    {
        for (int i = 2, j = 0; i <= n; ++i)
        {
            while (j && s[i] != s[j + 1])
                j = nextn[j];
            if (s[i] == s[j + 1])
                ++j;
            while ((j << 1) > i)
                j = nextn[j];
            res = (long long)(res * (num[j] + 1)) % MOD;
        }
    }

    inline void work()
    {
        while (T--)
        {
            res = 1;
            num[1] = 1;
            scanf("%s", s + 1);
            n = strlen(s + 1);
            GetNext();
            GetNum();
            cout << res << endl;
        }
    }
}

namespace IO2
{
    inline void GetNext()
    {
        nextn[0] = 0;
        nextn[1] = 0;
        //     for (int i = 1; i < (int)s.length(); ++i)
        //     {
        //         int j = nextn[i];
        //         while (j && s[j] != s[i])
        //             j = nextn[j];
        //         if (s[j] == s[i])
        //             nextn[i + 1] = j + 1;
        //         else
        //             nextn[i + 1] = 0;
        //     }
    }

    inline long long GetNum()
    {
        num[1] = 0;
        num[0] = 0;
        long long res = 1;
        //     for (int i = 2; i <= (int)s.length(); ++i)
        //     {
        //         int j = nextn[i];
        //         while (j)
        //         {
        //             /* code */
        //             if (2 * j <= i)
        //                 num[i] = num[i] + j - 1;
        //             j = nextn[j];
        //         }
        //         res *= num[i] + 1;
        //         res %= MOD;
        //     }
        return res;
    }

    inline void work()
    {
        while (n--)
        {
            cin >> s;
            memset(nextn, 0, sizeof(nextn));
            memset(num, 0, sizeof(num));
            GetNext();
            print(GetNum(), 1);
        }
    }
}

int main() {
    // freopen("zoo.in", "r", stdin);
    // freopen("zoo.out", "w", stdout);
    read(T);    
    IO::work();
    return 0;
    
}
