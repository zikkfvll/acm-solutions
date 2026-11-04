#include <iostream>
#include <string>

using namespace std;

bool isExtendedABCString(string s) {
	int n = s.length();
	int countA = 0, countB = 0, countC = 0;

	// Count the number of A's, B's and C's
	for (int i = 0; i < n; i++) {
		if (s[i] == 'A')
			countA++;
		else if (s[i] == 'B')
			countB++;
		else if (s[i] == 'C')
			countC++;
	}

	// Check if all A, B, C are present
	if (countA == 0 || countB == 0 || countC == 0) {
		return false;
	}

	// Check if countA + countB + countC equals the length of s
	if (countA + countB + countC != n) {
		return false;
	}

	int i = 0, j = 0, k = 0;

	// Find the first non-A character
	while (i < n && s[i] == 'A') {
		i++;
	}

	// Find the first non-B character
	while (j < n && s[j] == 'B') {
		j++;
	}

	// Find the first non-C character
	while (k < n && s[k] == 'C') {
		k++;
	}

	// Check if the substring from i to j-1 is an Extended B string,
	// substring from j to k-1 is an Extended C string,
	// and substring from k till the end is an Extended A string
	if (j > i && k > j && k == n) {
		return true;
	}

	return false;
}

int main() {
	string s;
	cin >> s;

	if (isExtendedABCString(s)) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}

	return 0;
}
