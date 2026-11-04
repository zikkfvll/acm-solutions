#include <bits/stdc++.h>
using namespace std;
int T;

template <typename T>
inline void read(T &ans) {
    char ch = getchar();
    double f = 1;
    ans = 0;
    for (; !isdigit(ch); ch = getchar())
        ch == '-' ? f = -1 : f = 1;
    for (; isdigit(ch); ch = getchar())
        ans = ((int)ans << 3) + ((int)ans << 1) + (ch & 15);
    ans *= f;
    return;
}
template <typename T, typename... Args>
inline void read(T &tmp, Args &...tmps) {read(tmp);read(tmps...);}

struct point {
    double x, y, z;
    bool operator<(const point &p) const {
        return z < p.z;
    }
} a[1010];

bool flag = 0, vis[1010];
int n;
double h, r;

namespace OI {
    inline double dist(double x1, double y1, double z1, double x2, double y2, double z2) {
        return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) + (z2 - z1) * (z2 - z1));
    }

    inline void dfs(point now, int nxt) {
        if (now.z + r >= h) {
            flag = 1;
            return;
        }
        vis[nxt] = 1;
        for (int i = 1; i <= n; ++i) {
            if (flag) return;
            if (!vis[i] && dist(now.x, now.y, now.z, a[i].x, a[i].y, a[i].z) <= 2 * r) dfs(a[i], i);
        }
    }

    inline void reset() {
        memset(vis, 0, sizeof(vis));
        memset(a, 0, sizeof(a));
        flag = 0;
    }

    inline void work() {
        for (read(T); T; --T) {
            reset();
            read(n, h, r);
            for (int i = 1; i <= n; ++i) read(a[i].x, a[i].y, a[i].z);
            sort(a + 1, a + n + 1);
            for (int i = 1; i <= n; ++i) if (a[i].z - r <= 0) dfs(a[i], i);
            cout << (flag ? "Yes" : "No") << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    OI::work();
    return 0;
}