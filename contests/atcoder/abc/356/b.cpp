#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; ++i) cin >> a[i];
    vector<vector<int>> x(n, vector<int>(m));
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> x[i][j];
    bool tt = true;
    for (int j = 0; j < m; ++j) {
        int total = 0;
        for (int i = 0; i < n; ++i) total += x[i][j];
        if (total < a[j]) {
            tt = false;
            break;
        }
    }
    if (tt) cout << "Yes";
    else  cout << "No";
    return 0;
}
