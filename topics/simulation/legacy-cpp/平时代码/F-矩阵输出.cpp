#include <iostream>
using namespace std;
int main (){
	int i,j,k=1,n;
	int a[60][60];
    cin >> n;
    for(int  i = 0;i < n; i++){
    	for(int j = 0; j < n ; j++){
    		cin >> a[i][j];
		}
	}
	for(int k = 2;k <= n * 2;k++) {
        for(i = n;i >= 1;i--){
        	int j =k - i;
        	if( i > 0 && i<n)
     	    	cout<<a[i][j]<<" ";
	    }
   }
   return 0;
} 
