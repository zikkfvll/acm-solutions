#include<bits/stdc++.h>
using namespace std;
int a, n, top = 1, cnt[110000];

struct aa {
	int hao,shu;
}que[1100000];

int main() {
	cin >> n;
	for(int i =1;i<=n;i++) {
		cin >>a;
		while(a>que[top-1].shu&&top>1) {
			cnt[que[top-1].hao] = i;
			--top;
		}
		que[top].shu=a;
		que[top].hao=i;
		++top;
	}
	for(int i =1;i<=n;i++) {
		cout<<cnt[i] <<endl;
	}
	return 0;
}
