#include<bits/stdc++.h> 

using namespace std;
const int MOD = 1e9 + 7 , N = 1000010 , M = 11;
typedef long long LL;
LL dp[N][M] , n;

int main( )
{
    cin >> n;
    dp[0][0] = 1;
    for(int i = 0 ; i < n ; i ++)
        for(int j = 0 ; j < 11 ; j ++)
            if(j == 10)          // 最终状态 
            {
                dp[i + 1][j] = (dp[i + 1][j] + 26 * dp[i][j]) % MOD;
            }
            else if(j == 9)        
            {
                dp[i + 1][j + 1] = (dp[i + 1][j + 1] + 26 * dp[i][j]) % MOD;
            }
            else if(j % 3 == 1) // j == 1 || j == 4 || j == 7
            {
                dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
                dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % MOD;
                dp[i + 1][j - 1] = (dp[i + 1][j - 1] + 24 * dp[i][j]) % MOD;
            }
            else
            {
                dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % MOD;
                dp[i + 1][j / 3 * 3] = (dp[i + 1][j / 3 * 3] + 25 * dp[i][j]) % MOD;
            }

    cout << (dp[n][9] + dp[n][10]) % MOD << '\n';
    return 0;
}