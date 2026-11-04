#include <iostream>
using namespace std;
int main()
{
   int n,i,a,b,c;
   char k;
   cin >> n;
   b=n-1;
   c=(1+n)*n/2;
   for(i=0 ; i<c ; i++){
   		k = 'A'+i;
        cout << k;
        if(i==n-1){
            cout << endl;
            n+=b;
            b--;
        }
     }
    return 0;
}
