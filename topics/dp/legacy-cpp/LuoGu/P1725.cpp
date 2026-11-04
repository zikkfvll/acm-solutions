#include<bits/stdc++.h>
using namespace std;

int n,l,r;
int a[3300000],q[3300000],f[3300000], cnt= 0;
int first = 1 , final = 1;

int main() {
	cin >> n >>l >>r;
	for(int i =0;i <=n;i++) {
		cin >> a[i];
	}
	memset(f,0xcf,sizeof(f));
	cnt = f[0];
	f[0] =0;
	int p =0;
	for(int i =l;i<=n;i++) {
		while(first <= final && f[q[final]] <= f[p]) final--;
		q[++final] = p;
		while(q[first]+r < i) first++;
		f[i] = f[q[first]] + a[i];
		p++;
	}
	for(int i =n+1-r;i<= n;i++) {
		cnt = max(cnt , f[i]);
	}
	cout<< cnt;
}

