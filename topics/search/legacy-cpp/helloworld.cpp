#include<bits/stdc++.h>
using namespace std;
int n , res;
int a[5005];
long long fac[14] = {0,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800};

inline void dfs(int pos,int sum){
    if(pos == n){
        res += fac[sum];
        return;
    }
    dfs(pos + 1,sum);
    int fl[10] , cnt = 0;
    for(int i = 1; i<=(1<<(n-pos));i+=2)
        if(a[i*(1 << pos) + 1] != a[(i-1)*(1<<pos)+1]+(1 << pos)){
            if(cnt == 4) break;
            fl[++cnt] = i;
            fl[++cnt] = i-1;
        }
        if(cnt == 4) return;
        for(int i = 1;i <= cnt;++i)
            for(int j = i+1;j <= cnt;++j) {
                if(fl[i] == fl[j]) return;
                if(a[fl[i]*(1 << pos) + 1] == a[fl[j]*(1 << pos) + 1]+(1 << pos)){
                    dfs(pos + 1,sum + fac[cnt]);
                    return;
                }
            }
}

int main(){
    cin >> n;
    for(int i =1;i <= (1 << n);++i) cin >> a[i];
    dfs(0,0);
    cout << res <<endl;
    return 0;
}

