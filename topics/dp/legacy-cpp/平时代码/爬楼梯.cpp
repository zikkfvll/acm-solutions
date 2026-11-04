#include<iostream>
using namespace std;
int main()
{
    unsigned int num[1001]={0 , 1 , 2 , 4};
    int n;
    cin>>n;
    for(int i = 4 ; i <= n ; i++)
    {
        num[i] = (num[i - 3]+num[i - 2]+num[i - 1]) % 998244353;
    }
    cout << num[n] <<endl;
}
