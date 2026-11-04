#include <bits/stdc++.h>
using namespace std;
int T;
int n;
long long a[105];
bool flag = 1;
int ans[210] ,ans2[210];
int main(){
    for(cin >> T; T; T--) {
        flag=0;
        memset(ans , 0 , sizeof ans);
        memset(ans2 , 0 , sizeof ans2);
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        if(n == 2) {
            cout << "Yes" << endl;
            continue;
        }
        // int ans = 0 , ans2 = 0;
        // for(int i = 0; i < n-1; i++) {
        //     ans = a[i] + a[i+1];
        //     if(ans != ans2 && i != 0){
        //         cout << "No" << endl;
        //         flag = 0;  
        //         break;
        //     }
        //     ans2 = ans;
        // }
        // if(flag)
        //     cout << "Yes" << endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) {
                if(i == 0) {
                    ans2[j] = a[i] + a[j];
                }
                else if(i != j) {
                    ans[j] = a[i] + a[j];
                    if(ans[j] == ans2[j] && i != 0) flag = 1;
                    ans2[j] =ans[j]; 
                }
            }    
        }
        if(flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
