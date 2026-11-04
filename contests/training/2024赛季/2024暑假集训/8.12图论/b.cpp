#include<bits/stdc++.h>
using namespace std;
#define il inline
#define int long long
#define pr pair<int,int>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define _ 0

const int N = 5e4 + 1000;

struct edge{
    int to;
    int last;
    int w;
};

struct edge e[N << 2];
int head[N] , dis[N];
int cnt = 0; 
bool vis[N];
int n, m, s, r, p;
int u, v, w;

inline void add(int u ,int v ,int w) {
    ++cnt;
    e[cnt].w = w;
    e[cnt].to = v;
    e[cnt].last = head[u];
    head[u] = cnt;
}

void SPFA() {
    deque<int> q;
    rep(i, 0, n + 10) dis[i] = INT_MAX;
    q.push_back(s);
    memset(vis, 0, sizeof(vis));
    vis[s] = 1; dis[s] = 0;
    while(!q.empty()) {
        int now = q.front(); q.pop_front(); vis[now] = 0;
        for(int i = head[now]; ~i; i = e[i].last) {
            int v = e[i].to;
            if(dis[v] > dis[now] + e[i].w) {
                dis[v] = dis[now] + e[i].w;
                if(!vis[v]) {
                    vis[v] = 1;
                    if(!q.empty() && dis[v] < dis[q.front()]) q.push_front(v);
                    else q.push_back(v);
                }
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> r >> p >> s;
    rep(i, 0, n + 10) head[i] = -1;
    rep(i, 1, r) cin >> u >> v >> w, add(u, v, w), add(v, u, w);
	rep(i, 1, p) cin >> u >> v >> w, add(u, v, w);
    SPFA();
    rep(i, 1, n) {
        if(dis[i] == INT_MAX) cout << "NO PATH" << endl;
		else cout << dis[i] << endl;
	}
    return ~~(0 ^ _ ^ 0);
}
