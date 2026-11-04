#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,k=0;
  cin>>n;
  for(int i = 31;i >= 0 ; i--){
    cout<<((n >> i)&1);
    k++;
	if(k == 4){
		cout<<" ";
		k = 0;
	}
  }
}

