#include <bits/stdc++.h>
using namespace std;
int n ,m[1005] ,a[1005];
int main() {
	scanf("%d",&n);
	for(int i = 1;i<=n;++i) scanf("%d",&a[i]);
	for(int i = 1;i<n;++i) m[i] = abs(a[i] - a[i+1]);
	sort(m+1,m+n);
	for(int i = 1;i<n;i++) {
		if(m[i] != i) {
			printf("Not jolly");
			return 0;
		}
	}
	printf("Jolly");
	return 0;
}
