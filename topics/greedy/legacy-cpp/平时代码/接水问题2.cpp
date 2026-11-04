#include<bits/stdc++.h>
using namespace std;
int n,m,x,b[100010];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>x;
    	int k=1;
    	for(int j=2;j<=m;j++)if(b[j]<b[k])k=j;
    	b[k]+=x;
	}
	int k=1;
	for(int i=2;i<=m;i++)if(b[i]>b[k])k=i;
    cout<<b[k];
    return 0;
}
