#include <bits/stdc++.h>
using namespace std;
int n, m;
char c[100000];
int a[100000];
int p, num, cnt;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i] >> c[i];
    cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> p >> num;
        if (a[cnt] != p) cnt = (cnt + num) % n;
        else cnt = n - 1 - ((n - 1 - cnt + num) % n);
    }
    cout << c[cnt] << endl;
    return 0;
}