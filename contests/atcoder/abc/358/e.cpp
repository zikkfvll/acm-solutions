#include <iostream>
#include <vector>

using namespace std;
const int MOD = 998244353;

int main() {
    int K;
    cin >> K;
    vector<int> C(26);
    for (int i = 0; i < 26; ++i) {
        cin >> C[i];
    }

    // Initialize dp array, where dp[l] is the number of valid strings of length l
    vector<int> dp(K + 1, 0);
    dp[0] = 1; // There's one way to make an empty string

    for (int i = 0; i < 26; ++i) {
        vector<int> new_dp(K + 1, 0);
        for (int length = 0; length <= K; ++length) {
            for (int count = 0; count <= C[i] && length + count <= K; ++count) {
                new_dp[length + count] = (new_dp[length + count] + dp[length]) % MOD;
            }
        }
        dp = new_dp;
    }

    int result = 0;
    for (int length = 1; length <= K; ++length) {
        result = (result + dp[length]) % MOD;
    }

    cout << result << endl;
    return 0;
}
