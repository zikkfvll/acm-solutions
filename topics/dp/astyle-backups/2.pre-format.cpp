#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int min_magic_cost(int n, int m, vector<int>& s, vector<int>& t, vector<vector<int>>& transformations) {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INF));
    dp[0][0] = 0;

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i > 0 && j > 0) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min({dp[i][j], dp[i - 1][j] + transformations[s[i - 1]][t[j - 1]], 
                                    dp[i][j - 1] + transformations[s[i - 1]][t[j - 1]],
                                    dp[i - 1][j - 1] + transformations[s[i - 1]][t[j - 1]]});
                }
            } else if (i > 0) {
                dp[i][j] = dp[i - 1][j] + transformations[s[i - 1]][0];
            } else if (j > 0) {
                dp[i][j] = dp[i][j - 1] + transformations[t[j - 1]][0];
            }
        }
    }

    return dp[n][n] >= INF ? -1 : dp[n][n];
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> s(n), t(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }

    vector<vector<int>> transformations(101, vector<int>(101, INF)); // 初始化为足够大的值
    for (int i = 0; i < m; ++i) {
        int ai, bi, ci;
        cin >> ai >> bi >> ci;
        transformations[ai][bi] = min(transformations[ai][bi], ci);
    }

    int result = min_magic_cost(n, m, s, t, transformations);
    cout << result << endl;

    return 0;
}
