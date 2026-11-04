# include <iostream>
using namespace std;

struct in {
	string name;
	int age, score;
} a[100000];

int main () {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].name >> a[i].age >> a[i].score;
		a[i].age++, a[i].score = a[i].score / 5 * 6;
		if (a[i].score > 400) {
			a[i].score = 400;
		}
		cout << a[i].name << " " << a[i].age << " " << a[i].score << endl;
	}
	return 0;
}
