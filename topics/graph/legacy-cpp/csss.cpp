#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool constructTree(int n, int m, vector<pair<int, int>> &events) {
	if (m != n - 1) {
		cout << "No" << endl;
		return false;
	}

	vector<int> degree(n + 1, 0);
	unordered_map<int, vector<pair<int, int>>> edges;

	for (const auto &event : events) {
		int u = event.first;
		int v = event.second;
		degree[u]++;
		degree[v]++;
		edges[u].push_back(event);
		edges[v].push_back(event);
	}

	vector<pair<int, int>> treeEdges;
	int leafNode = -1;

	for (int i = 1; i <= n; ++i) {
		if (degree[i] > 2) {
			cout << "No" << endl;
			return false;
		} else if (degree[i] == 1) {
			if (leafNode == -1) {
				leafNode = i;
			} else {
				cout << "No" << endl;
				return false;
			}
		} else if (degree[i] == 2) {
			for (const auto &event : edges[i]) {
				int u = event.first;
				int v = event.second;
				if ((u == i && degree[v] == 1) || (v == i && degree[u] == 1)) {
					treeEdges.push_back(event);
					degree[u]--;
					degree[v]--;
				}
			}
		}
	}

	if (treeEdges.size() != n - 1 || leafNode == -1) {
		cout << "No" << endl;
		return false;
	}

	cout << "Yes" << endl;
	for (const auto &edge : treeEdges) {
		cout << edge.first << " " << edge.second << endl;
	}

	return true;
}



int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, m;
		cin >> n >> m;

		vector<pair<int, int>> events(m);
		for (int i = 0; i < m; ++i) {
			cin >> events[i].first >> events[i].second;
		}

		if (!constructTree(n, m, events)) {
			cout << "No" << endl;
		}
	}

	return 0;
}
