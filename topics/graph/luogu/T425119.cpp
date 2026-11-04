#include <bits/stdc++.h>
using namespace std;
namespace fastOI{
    template<class T>
    inline void print(T ret,int flg=0){
        static int sta[35];
        T x=ret;int top=0;
        bool f=(ret<0);
        if(ret<0) x=-x;
        do{sta[top++]=x%10,x/=10;}while(x);
        if(f) putchar('-');
        while(top) putchar(sta[--top]+48);
        if(flg==0)putchar(' ');
        else if(flg==1)putchar('\n');
    }

    template<typename T>
    inline void read(T &ans){
        char ch=getchar();int f=1;ans=0;
        for(;!isdigit(ch);ch=getchar()) ch=='-'?f=-1:f=1;
        for(;isdigit(ch);ch=getchar()) ans=(ans<<3)+(ans<<1)+(ch&15);
        ans*=f;
        return;
    }
    template<typename T,typename ...Args>
    inline void read(T &tmp,Args &...tmps){read(tmp);read(tmps...);}
}
struct Edge {
	int to;
	int weight;
	Edge(int t, int w) : to(t), weight(w) {}
};

bool spfa(int st, vector<vector<Edge>> &gg, vector<int> &d, int k) {
	vector<int> in_queue(d.size(), 0);
	queue<int> q;
	d[st] = 0;
	q.push(st);
	in_queue[st] = 1;

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		in_queue[node] = 0;

		for (const Edge &edge : gg[node]) {
			for (int i = 1; i <= k; ++i) {
				int new_dist = d[node] + i;
				if (new_dist < d[edge.to]) {
					d[edge.to] = new_dist;
					if (!in_queue[edge.to]) {
						q.push(edge.to);
						in_queue[edge.to] = 1;
					}
				}
			}
		}
	}
	for (int i = 1; i < d.size(); ++i) for (const Edge &edge : gg[i]) if (d[i] == d[edge.to]) return false;
	return true;
}

void solve() {
	int n, m, k;
	cin >> n >> m >> k;

	vector<vector<Edge>> gg(n + 1);
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		gg[x].push_back(Edge(y, 0));
	}

	vector<int> d(n + 1, numeric_limits<int>::max());
	bool flag = spfa(1, gg, d, k);
	// if (flag) {
	// 	cout << "Yes" << '\n';
	// 	for (int i = 2; i <= n; ++i) cout << d[i] << " ";
	// 	cout << '\n';
	// } else 
	// 	cout << "No" << '\n';
    cout << "No" << '\n';
	
}

int main() {
	int T;
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	for (cin >> T; T; --T) solve();
	return 0;
}
