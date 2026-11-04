#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll; 
const int N = 50010;
int n,m,w;
ll T,a[N],b[N],c[N];

void merge(int l,int mid,int r){
	int i = l,j = mid + 1;
	for(int k = 1;k <= r;k++){
		if(j > r || (i <= mid && b[i] <= b[j])) c[k] = b[i++];
		else c[k] = b[j++];
	}
}

ll calc(int l,int r){
	if(r > n) r = n;
	int  t = min(m,(r - l + 1) >> 1);
	sort(b + w + 1 , b + r + 1); // 表示对新增加区间排序， 上升
	merge(l , w , r); // 采用归并方式，快速合并两个有序序列
	ll ans = 0;
	for(int i = 0;i < t ; i++)
		ans += (c[r - 1] - c[l = i] * (c[r - i] - c[ l + i ]));
	return ans;  //计算返回校验值 
	
}
void acm(){
	cin >> n >> m >> T;
	for(int i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
	}
	int ans = 0,l = 1,r = 1;
	w = 1;
	b[1] = a[1];
	while(l <= n){
		int p = 1;
		while(p){   //倍增模板 
			ll num = calc(1, r + p); // calc 计算扩展区间 [l,r+p] 的检验值 
			if(num <= T){
				w = r = min(n , r+p);
				for(int i = 1;i <= r; i++) b[i] = c[i]; //对归并结果进行复制
				if (r == n) break;
				p <<= 1; 
			}
			else p>>= 1;
		}
		ans++;
		l =r + 1;
	}
	cout << ans << endl;
}

int main(){
	freopen("geniusacm.in","r",stdin);
	freopen("geniusacm.out","w",stdout);
	int k;
	cin >> k;
	while(k--) acm();
	return 0;
}
