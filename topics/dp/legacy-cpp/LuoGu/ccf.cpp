#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX
int a[2005],b[2005];
bool cmp(pair<int,int> a,pair<int,int> b){
  return a.first>b.first;
}
int n;
int dp[2005][2005];
int res = -100000000;
int main(){
  cin >> n;
  pair<int,int> aa[2005];
  for(int i =1; i<= n;++i) cin >> aa[i].first >> aa[i].second;
  sort(aa+1,aa+n+1 ,cmp);
  memset(dp,0,sizeof(dp));
  for(int i = 0; i<= n;++i){
      dp[0][i] = -100000000;
      dp[i][n+1] = -100000000;
  }
  cout << "debug" << endl;
  dp[0][1] = 0;
  for(int i = 1; i<= n;++i)
      for(int j = 0; j<= n;++j)
          dp[i][j] = max(dp[i-1][j],dp[i - 1][max(j-aa[i].first , 0)+1]+aa[i].second);
  for(int i = 0; i<= n;++i)
      res = max(res,dp[n][i]);
    
  cout << res << endl;
  return 0;
}
