#include <bits/stdc++.h>
using namespace std;
int a[20005];
int n,b,sum , cnt;
int main() {
	scanf("%d%d",&n,&b);
	for(int i = 0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n,greater<int>());
	while(sum < b) {
		sum+=a[cnt];
		++cnt;
	}
	cout<<cnt;
	return 0;
}
