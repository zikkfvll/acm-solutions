#include <bits/stdc++.h>
using namespace std;
int minn=10000 , n;
int a[100005];
long long res;
inline void init() {
    cin >> n;
    for(int i=1;i <= n;i++) {
        cin >> a[i];
        minn=min(minn ,a[i]);
    }
    for(int i=1;i <= n;++i) a[i] -= minn;
    res = minn;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    init();
    int flag = 0;
    while(true) {
        if(!a[flag]) {
            flag++;
            if(flag == n+1) break;
            }
            minn = a[flag];
            for(int i = flag ;i <= n;++i) {
                if(!a[i]) break;
                minn = min(minn , a[i]);
            }
            for(int i = flag ;i <= n;++i){
                if(!a[i]) break;
                a[i] -= minn;
            }
            res += minn;
    }
    cout << res;
    return 0;
}
