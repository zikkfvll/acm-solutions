#include <iostream>
using namespace std;
int main ()
{
    int g[20] , s , c = 0;
    for(int i = 0; i < 10; i++){
 		cin >> g[i];
    } 
    cin >> s;
    for(int j = 0 ; j < 10 ; j++){
    	if(s + 30 >= g[j]){
    		c++;
		}
	}
	cout << c;
   return 0;
}

