#include <iostream>
using namespace std;
int fun(int  n)
{
    int a;
    int sum=0;
        for(i=2;i<n;i++) {
            if(0 == n%i) {
                sum+=i;
            }
        }
    return sum;

}
int main()
{ 
    int  n,sum;
	cin >> n;
    sum = fun(n);
    cout << sum;
}
