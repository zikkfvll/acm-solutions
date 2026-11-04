#include<bits/stdc++.h>
using namespace std;
#define N 200010
int n,m,a[N],x[N],y[N],lang[N*3],tot,k,ans[N*3];
int find(int f){
	return lower_bound(lang+1,lang+k+1,f)-lang;
}
int main(){
	freopen("cinema.in","r",stdin);
	freopen("cinema.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		lang[++tot]=a[i];
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		scanf("%d",&x[i]);
		lang[++tot]=x[i];
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&y[i]);
		lang[++tot]=y[i];
	}
	sort(lang+1,lang+1+tot);
	k=unique(lang+1,lang+1+tot)-lang-1;
	memset(ans,0,sizeof ans);
	for(int i=1;i<=n;i++) ans[find(a[i])]++;
	int ans0=1,ans1=0,ans2=0;
	for(int i=1;i<=m;i++){
		int ansx=ans[find(x[i])],ansy=ans[find(y[i])];
		if(ansx>ans1||(ansx==ans1&&ansy>ans2)){
			ans0=i;
			ans1=ansx;
			ans2=ansy;
		}
	}
	cout<<ans0<<"\n";
	return 0;
}
