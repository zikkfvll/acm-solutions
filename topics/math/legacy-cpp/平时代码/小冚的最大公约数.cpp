#include <iostream>
using namespace std;
long long f(long long a, long long b){
    return b == 0 ? a:f(b, a%b);
}

int main()
{
   long long a , b;
   cin >> a >> b;
   cout << f(a , b);
   return 0;
}
