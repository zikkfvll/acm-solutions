#include <iostream>
using namespace std;
int main ()
{
    int a[20] , c = 0;
    for(int i = 0; i < 5; i++){
 		cin >> a[i];
    } 
    for(int j = 0 ; j <= 9 ; j++){
    	c = 0;
    	for(int t = 0; t < 5;t++){
    		if(a[t] != j){
    			c++;
			}
		}
		if(c >= 5){
			cout << j <<endl;
		}
	}
   return 0;
}

