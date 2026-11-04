#include<iostream>
#include<algorithm>
using namespace std;
#define N 100
int main(){
	int n , m , w , a[N]={0};
	cin >> n >> m;
	for(int i = 0; i < n ; i++) {
		cin >> w;
		a[0] += w;
		sort(a , a + m);
	}
	cout << a[m - 1] << endl;
    return 0;m
}
