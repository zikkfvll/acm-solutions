#include<bits/stdc++.h>
#define il inline

const int MAXN = 1e7 + 10;
const int MOD = 998244353;
using namespace std;
int n,ans;
string s;
int sum[MAXN];
vector<int>id;  
struct node{
    int id,val;
    bool friend operator<(node a,node b){
        return a.val < b.val;
    }
};
priority_queue<node,vector<node>,less<node> >q;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL),cout.tie(NULL);
    cin >> n;
    cin >> s;
    s = '*' + s;
    for(int i = 1;i <= n;++i){
        sum[i] = (s[i] == 'B') ? 1 : -1;
        sum[i] += sum[i - 1];
    }
    printf("\n");
    for( int i = 1;i <= n;++i){
        if(s[i] == 'B'){
            node p;
            p.val = sum[i - 1],p.id = i;
            q.push(p);
        }
        if(q.empty()){
            continue;
        }
        if(s[i] == 'W' && sum[i] - q.top().val < 0){
            ans = (ans + (i - q.top().id - 1) % MOD) % MOD,q.pop();
            --i;
        }
    }
    while(!q.empty()){
        ans = (ans + (n - q.top().id) % MOD) % MOD;
        q.pop();
    }
    printf("%d ",ans);
	return 0;
}
