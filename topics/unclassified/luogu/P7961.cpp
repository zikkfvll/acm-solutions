#include <bits/stdc++.h>
using namespace std;
int n , m , k;
long long v[105];
int main(){
    cin >> n >> m >> k;
    for(int i = 1 ; i <= m-1 ; i++) cin >> v[i];
    sort(v+1,v+m);
    return 0;
}
