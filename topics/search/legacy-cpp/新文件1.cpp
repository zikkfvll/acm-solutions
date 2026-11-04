#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

int minCost = INT_MAX;

// 函数用于判断字符串 a 是否为字符串 b 的前缀
bool isPrefix(const string &a, const string &b) {
	if (a.length() > b.length())
		return false;
	for (int i = 0; i < a.length(); ++i) {
		if (a[i] != b[i])
			return false;
	}
	return true;
}

void dfs(const string &T, const vector<vector<string>> &bags, int cost, string current, int index) {
	// 如果当前拼接的字符串已经超过目标字符串 T 的长度，则剪枝
	if (current.length() > T.length())
		return;
	// 如果当前成本已经超过当前最小成本，则剪枝
	if (cost >= minCost)
		return;
	// 如果当前拼接的字符串与目标字符串 T 匹配，则更新最小成本并返回
	if (current == T) {
		minCost = min(minCost, cost);
		return;
	}
	// 遍历当前袋子中的字符串，进行选择
	for (const string &s : bags[index]) {
		// 如果当前拼接的字符串与目标字符串 T 的前缀匹配，则继续递归
		if (isPrefix(current + s, T)) {
			dfs(T, bags, cost + 1, current + s, index);
		}
	}
	// 继续递归，选择下一个袋子
	if (index + 1 < bags.size()) {
		dfs(T, bags, cost, current, index + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string T;
	int N;
	cin >> T >> N;
	vector<vector<string>> bags(N);
	for (int i = 0; i < N; ++i) {
		int A;
		cin >> A;
		bags[i].resize(A);
		for (int j = 0; j < A; ++j) {
			cin >> bags[i][j];
		}
	}
	dfs(T, bags, 0, "", 0);
	if (minCost == INT_MAX)
		cout << -1 << endl;
	else
		cout << minCost << endl;

	return 0;
}
