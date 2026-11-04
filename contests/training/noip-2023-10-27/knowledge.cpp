#include <bits/stdc++.h>
using namespace  std;

int _IO_c;
unsigned int seed;
unsigned int randnum()
{
    seed ^= seed << 13;
    seed ^= seed >> 17;
    seed ^= seed << 5;
    return seed;
}

inline int read(int *x)
{
    scanf("%d", x);
    return *x;
}

inline void init_case(int *m, int *a, int *b, int *d, int p[])
{
    int i;
    scanf("%d%u%d%d%d%d", m, &seed, a, b, &_IO_c, d);
    for (i = 1; i <= *m; i++)
    {
        if (randnum() % _IO_c == 0)
            p[i] = -1;
        else
            p[i] = randnum() % *b;
    }
}

inline void update_ans(unsigned int *ans_sum, unsigned int cur_ans, int no)
{
    const static unsigned int mod = 998244353;
    *ans_sum ^= (long long)no * (no + 7) % mod * cur_ans % mod;
}

int main()
{
    static int p[2000005];
    int T;
    int m, a, b, d, i;
    read(&T);
    while (T--)
    {
        unsigned int ans_sum = 0, cur_ans = 0;
        init_case(&m, &a, &b, &d, p);
        for (i = 1; i <= m; i++)
        {
            //......处理操作
            update_ans(&ans_sum, cur_ans, i);
        }
        printf("%u\n", ans_sum);
    }
    return 0;
}