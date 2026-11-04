#include<bits/stdc++.h>
using namespace std;
int d,res,n,u,v;
const int INF=2147483647;
long long dis[1000001];
struct edge{
	int to;
	int w;
}o;
//struct edge o;
vector<edge>a[1000001];
queue<int>q;
int vis[100001];

void SPFA() {
	q.push(1);
	vis[1]=1;
	dis[1]=0;
	while(!q.empty()){	
        int xx=q.front();
        q.pop();
        vis[xx]=0;
        for(int i=0;i<a[xx].size();i++){
            o=a[xx][i];
            int yy=o.to;
            int ww=o.w;
            if(dis[yy]>dis[xx]+ww){
                dis[yy]=dis[xx]+ww;
                if(!vis[yy]){
                    q.push(yy);
                    vis[yy]=1;
                }
            }
        }
	}
}

inline void init() {
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        cin>>u>>v;
        o.to=v;
        o.w=1;
        a[u].push_back(o);
        o.to=u;
        a[v].push_back(o);
    }
    for(int i=1;i<=n;i++) dis[i]=INF;
}

inline void solve() {
    init();
    SPFA();
	for(int i=1;i<=n;i++) if(dis[i]<=d&&dis[i]!=0) res++;
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	solve();
	return 0;
    
}