#include <bits/stdc++.h>
using namespace std;
int n;
long long a[5005];

inline long long calc(long long l, long long r, long long high)
{
    if (l == r)
        return 1;
    long long res, m = -1, t = r - l + 1;
    for (int i = l; i <= r; i++)
        if (a[i] < m || m == -1)
            m = a[i];
    res = m - high;
    for (int i = l; i <= r; i++)
    {
        int pos;
        if (a[i] == m)    
            continue;
        for (int j = i; j <= r; j++)
        {
            pos = j;
            if (j == r || a[j + 1] == m)
                break;
        }
        res += calc(i, pos, m);
        i = pos + 1;
    }
    return min(res, t);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cout << calc(1, n, 0);
    return 0;
}