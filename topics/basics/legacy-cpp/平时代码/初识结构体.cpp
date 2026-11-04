#include <bits/stdc++.h>
using namespace std;
struct Data {
	int a;
	int b;
	char c;
};
int main()
{
	int n;
	
	Data data[100000];
	
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> data[i].a >> data[i].b >> data[i].c;
	}
	for(int i = 0; i < n; i++) {
		printf("%d %d %c\n",data[i].a,data[i].b,data[i].c);
	}
	return 0;
}
