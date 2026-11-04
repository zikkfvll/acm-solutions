#include <bits/stdc++.h>
using namespace std;
struct Data {
	int a;
	int b[35];
	string c;
};
int main()
{
	int n;
	Data data[100000];
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> data[i].a ;
		for(int j = 0; j < data[i].a; j++) {
			cin >> data[i].b[j] ;
		}
		cin >> data[i].c;
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < data[i].a; j++) {
			printf("%d ",data[i].b[j]);
		}
		printf("%s\n" , data[i].c.c_str());
	}
	return 0;
}
