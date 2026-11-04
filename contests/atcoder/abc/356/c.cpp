#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> mapp(m, vector<int>(n + 1, 0));
    vector<char> results(m);

    for (int i = 0; i < m; i++) {
        int c;
        cin >> c;
        results[i] = 'x';
        for (int j = 0; j < c; j++) {
            int key;
            cin >> key;
            mapp[i][key] = 1;
        }
    }
    int t = 0;
    for (int m = 0; m < (1 << n); m++) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) if (m & (1 << (i - 1))) cnt++;
        if (cnt >= k) {
            bool flag = true;
            for (int i = 0; i < m; i++) {
                int sum = 0;
                for (int j = 1; j <= n; j++) if (m & (1 << (j - 1))) sum += mapp[i][j];
                if ((sum < k && results[i] == 'o') || (sum >= k && results[i] == 'x')) {
                    flag = false;
                    break;
                }
            }
            if (flag) t++;
        }
    }
    cout << t << endl;
    return 0;
}
