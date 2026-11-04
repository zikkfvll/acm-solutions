#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5005;
const int mod=1000000007;
int a[N],n,m,s,t,ans=1;
signed main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin>>n>>m>>s>>t;
	for(int i=1;i<=m;i++){
		int x,l,r;
		cin>>x>>l>>r;
		l=l-s+1;
		r=r-s+1;
		for(int i=l;i<=r;i++){
			a[i]--;
		}
	}
	for(int i=1;i<=t-s+1;i++){	
		cout << a[i] << " ";
		ans=ans*(n+a[i])%mod;
	}
	cout<<ans;
}