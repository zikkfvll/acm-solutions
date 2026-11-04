#include <bits/stdc++.h>
using namespace std;
int T;

struct point {
	double x, y, z;

} a[1010];

bool flag = 0, vis[1010];
int n;
double h, r;

inline double dist(double x1, double y1, double z1, double x2, double y2, double z2) {
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) + (z2 - z1) * (z2 - z1));
}

inline void dfs(point now, int nxt) {
	if (now.z + r >= h) {
		flag = 1;
		return;
	}
	vis[nxt] = 1;
	for (int i = 1 ; i <= n ; ++i) {
		if (flag)
			return;
		if (!vis[i] && dist (now.x, now.y, now.z, a[i].x, a[i].y, a[i].z) <= 2 * r)
			dfs(a[i], i);
	}
}

inline void reset() {
	memset(vis, 0, sizeof(vis));
	memset(a, 0, sizeof(a));
	flag = 0;
}

int main() {
	for (cin >> T; T; --T) {
		reset();
		cin >> n >> h >> r;
		for (int i = 1 ; i <= n ; ++i)
			cin >> a[i].x >> a[i].y >> a[i].z;
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; ++i)
			if (a[i].z - r <= 0)
				dfs(a[i], i);
		cout << (flag ? "Yes" : "No") << endl;
	}
	return 0;
}