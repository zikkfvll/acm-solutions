#include<bits/stdc++.h>
using namespace std;
#define il inline
#define int long long
#define pr pair<int,int>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define _ 0

const int N = 3e4 + 1000;

struct edge{
    int to;
    int last;
    int w;
};

struct edge e[N];
int head[N] , dis[N];
int cnt = 0; 
bool vis[N];
int n, m, s, r, p;

struct node {
    int dis;
    int u;
    bool operator < (const node& a) const { 
        return a.dis < dis;
    }
};

priority_queue<node> q;

inline void add(int u ,int v ,int w) {
    ++cnt;
    e[cnt].w = w;
    e[cnt].to = v;
    e[cnt].last = head[u];
    head[u] = cnt;
}

void dijkstra( ) {
    rep(i, 1, n) dis[i] = INT_MAX;
    dis[s] = 0;
    q.push((node){0, s});
    while (!q.empty()) {
        auto u = q.top();
        q.pop();
        auto x = u.u;
        if (vis[x]) continue;
        vis[x] = 1;
        for (int i =  head[x]; i; i = e[i].last) {
            int y = e[i].to;
            if(dis[y] > dis[x] + e[i].w) {
                dis[y] = dis[x] + e[i].w;
                if(!vis[y]) q.push({dis[y], y});
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> r >> p >> s;
    rep(i, 1, r){
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w), add(v, u, w);
    }
	rep(i, 1, p){
		int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
	}
    dijkstra();
    rep(i, 1, n) {
        if(dis[i] == INT_MAX) cout << "NO PATH" << endl;
		else cout << dis[i] << endl;
	}
        
    return ~~(0 ^ _ ^ 0);
}
/*

6 9 4
1 2 5
2 1 5
3 4 5
4 3 5
5 6 10
6 5 10
3 5 -100
4 6 -100
1 3 -10

*/