#include<iostream>
using namespace std;
int main()
{
    int x , y;
    cin >> x >> y;
    int t = 2 * y;
    for (int i = y + 1 ; i <= x ; i++)
    	t += i;
    cout << t;

}
