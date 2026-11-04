#include <bits/stdc++.h>
using namespace std;
int n ,m ,a[5000010];
int k;
int main() {
	scanf("%d%d",&n,&k);
	for(int i = 0;i<n;i++) scanf("%d",&a[i]);
	nth_element(a , a+k , a+n);
	printf("%d",a[k]);
	return 0;
}
