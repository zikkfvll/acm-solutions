#include <bits/stdc++.h>
#define LL long long
#define MOD 9901
using namespace std;
LL a, b, cnt = 0, res = 1, n[10010][2], s;

inline LL fastPow(LL a, LL n) {
    LL res = 1;
    while (n) {
        if (n & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        n >>= 1;
    }
    return res % MOD;
}

inline LL inv(int x, int y) {
    int k = 0;
    y = y * b;
    if (x % MOD == 1) k = (y + 1) % MOD;
    else k = (fastPow(x % MOD, y + 1) - 1) % MOD * fastPow((x - 1) % MOD, MOD - 2) % MOD;
    return k % MOD;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> a >> b;
    if (a == 0) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 2; i * i <= a; ++i) {
        if (a % i == 0) {
            n[++cnt][0] = i;
            n[cnt][1] = 1;
            a = a / i;
            while (a % i == 0) {
                n[cnt][1]++;
                a = a / i;
            }
        }
    }
    if (a != 1) n[++cnt][0] = a,n[cnt][1] = 1;
    for (int i = 1; i <= cnt; ++i) res = res * inv(n[i][0], n[i][1]) % MOD;
    cout << (res % MOD + MOD) % MOD << endl;
    return 0;
}