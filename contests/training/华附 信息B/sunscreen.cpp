#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

typedef pair<int , int> PII; 

const int N = 2510;
int C , L;
PII cow[N] , spf[N];
//pair : first second
// cow.first  : min , cow.second : max
// spf.first : spf , spf.second : cover
int main(){
	cin >> C >> L;
	for(int i = 1; i <= C; i++) scanf("%d %d", &cow[i].first, &cow[i].second);
	for(int i = 1; i <= L; i++) scanf("%d %d", &spf[i].first, &spf[i].second);
	sort(cow + 1 , cow + C + 1 , greater<PII>()); // minSPF 下降排序 
	sort(spf + 1 , spf + L + 1 , greater<PII>()); // spf 下降排序 
	int ans = 0;
	for(int i = 1; i <= C; i++){
		for(int j = 1;j <= L; j++){
			if(spf[j].second && spf[j].first >= cow[i].first &&spf[j].first <= cow[i].second){
				ans++;
				spf[j].second--;
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
