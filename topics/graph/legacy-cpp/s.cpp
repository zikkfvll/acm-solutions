#include <iostream>
#include <cstdio>
using namespace std;
int in[100005];
void solve()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) in[i] = 0;
	for (int i = 1; i < n; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		in[u]++, in[v]++;
	}
	for (int i = 1; i <= n; i++)
		if (in[i] % 2 == 0) //度为偶数，先手必胜 
		{
			puts("Hifuu");
			return;
		}
	puts("Luna");
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) solve();
	return 0;
}

