#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<int> x(n), y(m);
        for (int i = 0; i < n; ++i) {
            cin >> x[i];
        }
        for (int i = 0; i < m; ++i) {
            cin >> y[i];
        }

        long long count = 0;

        // 计算小 Y 成为胜者的情况
        for (int i = 0; i <= n; ++i) { // 小 Y 的通过次数
            for (int j = 0; j <= m; ++j) { // 小 Z 的通过次数
                if (i == 0 && j == 0) continue; // 都没通过的情况

                long long penaltyY = (i > 0 ? (i - 1) * 20 + x[i - 1] : LLONG_MAX);
                long long penaltyZ = (j > 0 ? (j - 1) * 20 + y[j - 1] : LLONG_MAX);

                if (penaltyY < penaltyZ) {
                    count = (count + 1) % MOD;
                } else if (penaltyY == penaltyZ && i > 0 && j > 0) {
                    // 如果罚时相同且都通过，算作一种共享胜者的情况
                    count = (count + 1) % MOD;
                }
            }
        }

        cout << count << endl;
    }

    return 0;
}