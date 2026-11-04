#include <bits/stdc++.h>
using namespace std;
long long a[1000000001] , n;
int main(){
    cin >> n;
    for(int i=1;i <=n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    if(n%2==0) cout << a[n] << " " << a[(n+2)/2] << " " << a[1] << endl;
    else cout << a[n] << " " << a[(n+1)/2] << " " << a[1] << endl;
    return 0;
}

