#include <iostream>
using namespace std;

int main (){
	int n,a[60][60];
    cin >> n;
    for(int  i = 0;i < n;i++){
    	for(int j = 0;j < n;j++){
    		cin >> a[i][j];
		}
	}
	for(int k = 0;k <= 2*n;k++) {
        for(int i = k;i >= 0;i--){
        	int j =k - i;
        	if( i >= 0 && i < n &&  j < n)
     	    	cout << a[i][j] <<" ";
	    }
   }
   return 0;
} 

