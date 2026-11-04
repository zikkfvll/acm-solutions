#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    int k;
    cin >> k;

    // 用 map 存储巧克力的位置及其数量
    map<pair<long long, long long>, int> mp;

    for (int i = 0; i < k; i++) {
        long long x, y;
        cin >> x >> y;
        // 对应的位置 +1
        mp[{x - 1, y - 1}]++;
    }

    long long maxChocolatesForW = 0;
    
    // total chocolates in the right-upper rectangle
    long long cnt = 0;
    
    // Calculate total chocolates initially
    for (const auto& entry : mp) {
        cnt += entry.second;
    }

    // Iterate through possible cuts (x, y)
    for (long long y = 0; y <= m; y++) {
        for (long long x = 0; x <= n; x++) {
            // Count chocolates in the region for W (right upper)
            long long chocolatesForW = 0;

            // Calculate how many chocolates are in this cut:
            for (const auto& entry : mp) {
                long long cx = entry.first.first;
                long long cy = entry.first.second;
                
                // If the chocolate is in the right-upper section
                if (cx >= x && cy >= y) {
                    chocolatesForW += entry.second;
                }
            }

            // Update the maximum chocolates W can get
            maxChocolatesForW = max(maxChocolatesForW, chocolatesForW);
        }
    }

    // Output the result
    cout << maxChocolatesForW << endl;

    return 0;
}
