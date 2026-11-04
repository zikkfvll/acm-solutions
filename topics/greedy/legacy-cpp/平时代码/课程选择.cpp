#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
struct game
{

    int begin;
    int end;
} member[1100];
int cmp(game a , game b)
{
    return a.end<b.end;
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> member[i].begin >> member[i].end;
    sort(member , member + n , cmp);
    int cnt = 1;
    int flag = member[0].end;
    for(int i = 1; i < n; i++)
    {
        if(member[i].begin >= flag)
        {
            cnt++;
            flag = member[i].end;
        }
    }
    cout << cnt;
    return 0;
}

