#include <iostream>
using namespace std;
int main ()
{
   int a[110] ,n, min;
   cin >> n;
   min = a[0];
   for(int i = 0; i < n; i++){
		cin >> a[i];
		if(min >= a[i]){
			min = a[i];
		}
   } 
	cout << min;
   return 0;
}

