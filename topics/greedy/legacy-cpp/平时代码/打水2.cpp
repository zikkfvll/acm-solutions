#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int ans[1100];
int p[1100];

bool c(int a,int b){
	return ans[a] < ans[b];
}

int main(){
	int n , sum;
	cin >> n;
	
	for(int i = 1;i <= n;++i){
		cin >> ans[i];
		p[i] = i;
	}
	
	sort(p + 1, p + n + 1,c);
	
	for(int i = 1;i <= n;++i){
		cout << p[i] << " "; 
	}
	
	sort(ans + 1 , ans + n + 1);
	
    cout << endl;
    
    for(int i = 1;i <= n;++i){
        sum += (n-i) * ans[i];
    }
    
    cout << fixed << setprecision(2) << sum*1.0/n;
} 
