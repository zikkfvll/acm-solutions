#include<iostream>
using namespace std;
int main()
{
    int num[50]={0,1,2};
    int n;
    cin>>n;
    for(int i = 3;i <= n ;i++)
    {
        num[i]=num[i-1]+num[i-2];
    }
    cout<<num[n];
}
