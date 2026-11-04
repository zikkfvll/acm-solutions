#include<bits/stdc++.h>
using namespace std;
int n, m, res;
vector<pair<int, int>> pigs(m);
int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	cin >> n >> m;
	vector<int> wind(n);
	for (int i = 0; i < n; ++i) cin >> wind[i];
	for (int i = 0; i < m; ++i) cin >> pigs[i].first >> pigs[i].second;
	sort(wind.begin(), wind.end());
	sort(pigs.begin(), pigs.end());
	vector<bool> used(n, 0);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (!used[j] && wind[j] >= pigs[i].first && wind[j] <= pigs[i].second) {
				++res;
				used[j] = 1;	
				break;
			}
		}
	}
	cout << res << '\n';
	return 0;
}
