#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N = 5e5 + 10;
int a[N],b[N],n;
ll ans;

void merge (int l, int mid, int r){
	if(l == r) return;
	if( l + 1 == r){
		if(a[l] > a[r]){
			ans++;
			swap(a[l], a[r]);
		}
		return;
	}
	merge (l , (l + mid) >> 1 , mid);
	merge(mid + 1,(mid + 1 + r) >> 1 , r);
	int i = l, j = mid + 1;
	for( int w = 1;w <= r;w++){
		if(j > r||(i < mid &&a[i] <= a[j]))
			b[w] = a[i++];
		else{
			b[w] = a[j++];
			ans += mid - i + 1;
		}
	}
	for(int w = 1;w <= r ; w++){
		a[w] = b[w];
	}
}
int main(){
	while (cin >> n , n){
		for (int i = 1; i <= n ;i ++){
			cin >> a[i];
		}
		ans = 0;
		merge(1 , (1 + n) >> 1 , n);
		cout << ans << endl;
	}
	return 0;
} 
