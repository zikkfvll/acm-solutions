#include<bits/stdc++.h>
#define int long long
#define il inline
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define _ 0
using namespace std;

const int N = 5e5 + 1000;
int n, m;
int u, v;
int book[N], deg[N], d[N];
bool vis[N];
int head[N],cnt; 

struct Edge { 
    int nxt, to;
}e[N << 1];

il void add(int u,int v) { e[++cnt].nxt = head[u]; head[u] = cnt; e[cnt].to = v;}
vector<int> g;
struct point {
    int x, y;
    point(int x = 0, int y = 0): x(x), y(y) {}
};
vector<point> res;

il void fre(){
    freopen("C://Users//y//Downloads//.in", "r", stdin); 
    freopen("C://Users//y//Downloads//a.out", "w", stdout);
}

il bool cmp(point a, point b) {
    if(a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

il void dfs(int u) {
    book[u] = 1;
    g.push_back(u);
    for(int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        ++deg[u];
        if(book[v]) continue;
        dfs(v);
    }
}

il void bfs() {
    if(g.size() <= 1) return;
    queue<int> q;
    for(auto i : g) {
        d[i] = deg[i];
        if(deg[i] == 1) q.push(i);
    }
    cnt = 0;
    while(!q.empty()) {
        int x = q.front(); q.pop();
        for(int i = head[x]; i; i = e[i].nxt) {
            int v = e[i].to;
            if(vis[v]) continue;
            deg[v]--, deg[x]--;
            if(deg[v] == 1) q.push(v);
        }
        if(!deg[x]) vis[x] = 1, cnt++;
    }
    if(cnt == g.size()) {
        for(auto i : g) {
            if(d[i] == 1) {
                for(int j = head[i]; j; j = e[j].nxt) {
                    int v = e[j].to;
                    res.push_back(point(i, v));
                }
            }
        }
        return ;
    }
    for(auto i : g) {
        if(vis[i]) continue;
        for(int j = head[i]; j; j = e[j].nxt) {
            int v = e[j].to;
            if(vis[v]) res.push_back(point(i, v));
        }
    }
}

signed main() {
    //freOI(Name);
    //fre();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;
    rep(i ,1, m) cin >> u >> v, add(u, v), add(v, u);
    rep(i ,1, n) {
		if(book[i]) continue;
		g.clear();//多测清空
		dfs(i), bfs();
	}
	cout << res.size() << endl;
	sort(res.begin(), res.end(), cmp);
	for(auto i:res) cout << i.x << " " << i.y << endl;
    return ~~(0 ^ _ ^ 0);
}

