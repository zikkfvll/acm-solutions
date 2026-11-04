#include <iostream>
using namespace std;
int a , b;
void swap()
{
    int temp=a;
    a=b;
    b=temp;
}
int main()
{
    int a , b;
	cin >> a >> b; 
    swap(a,b);
    cout << a << " " << b;
    return 0;
}
