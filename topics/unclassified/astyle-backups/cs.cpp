#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	// Read input
	int N;
	cin >> N;
	string S;
	cin >> S;
	vector<int> C(N);
	for (int i = 0; i < N; ++i) {
		cin >> C[i];
	}

	// Calculate the minimum total cost
	int total_min_cost = 0;
	for (int i = 0; i < N - 1; ++i) {
		if (S[i] == '0' && S[i + 1] == '1') {
			total_min_cost += C[i];
		}
	}
	for (int i = 1; i < N; ++i) {
		if (S[i] == '1' && S[i - 1] == '0') {
			total_min_cost += C[i];
		}
	}

	// Print the answer
	cout << total_min_cost << endl;

	return 0;
}
