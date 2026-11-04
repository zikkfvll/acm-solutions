#include <bits/stdc++.h>
using namespace std;
int n;
int cnta = 0, cntb = 0;

int main() {
	cin >> n;
	while (n--) {
		int a, b;
		cin >> a >> b;
		cnta += a, cntb += b;
		cout << cnta <<  " " << cntb << "\n";
	}
	if (cnta > cntb)
		printf("Takahashi");
	else if (cnta = cntb)
		printf("a");
	else if (cnta < cntb)
		printf("Aoki");
	return 0;
}