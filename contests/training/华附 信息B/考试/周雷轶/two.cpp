#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
map<ll , int>vis;
int n , x;
int main(){
	//freopen("two.in","r",stdin);
	//freopen("two.out","w",stdout);
	cin >> n;
	int cnt = 0, maxn = 0;
	while(n--){
		cin >> x;
		vis[x]++;
		if(vis[x] == 2){
			ll i = x;
			while(vis[i] == 2){
				vis[i] -= 2;
				vis[i + 1]++;
				i++;
			}
		} 
	} 
	map<ll,int>::iterator it;
	for(it = vis.begin(); it != vis.end();it++){
		if(it->second != 0){
			cnt ++;
			if(it->first != maxn)
				maxn = it -> first;
		} 
	} 
	cout << maxn + 1-cnt << endl;
	return 0;
} 
