#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,s;
    int MAX,temp;
    cin >> n >> s >> MAX >> temp;
    MAX += temp;
    int a[n];
    int cnt = 0;
    for(int i = 0;i < n;i++)
    {
        int temp1;
        cin >> temp;
        if(temp > MAX)
            cin >> temp1;
        else
            cin >> a[cnt++];
    }
    sort(a , a + cnt);
    int sum = 0;
    for(int i = 0;i < cnt;i++)
    {
        s -= a[i];
        if(s < 0)
            break;
        sum++;
    }
    cout << sum << endl;
    return 0;
}
