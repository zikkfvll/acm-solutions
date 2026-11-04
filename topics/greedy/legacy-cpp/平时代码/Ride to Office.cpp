#include<iostream>
#include<cmath>
#include<climits> 
using namespace std;
int a[1001][1001],t[1001];
int main()
{
    int n ;
    while(cin >> n && n != 0)
    {
        int mint = INT_MAX;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][0]>>a[i][1];
            if(a[i][1]>=0)
                {
                    t[i]=ceil(4500*3.6/a[i][0]+a[i][1]);
                    if(mint>t[i]) mint=t[i];
                }
        }
        cout<<mint<<endl;
    }
    return 0;
}
