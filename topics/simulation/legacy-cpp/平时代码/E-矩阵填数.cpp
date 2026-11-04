#include <iostream>
using namespace std;

int main (){
	int n , y = 1 , a[60][60];
    cin >> n;
	for(int k = n-1;k >= 1-n;k--) {
        for(int i = 0;i < n;i++){
        	int j = i - k;
        	if( i >= 0 && i < n && j >= 0 && j < n){
				a[i][j] = y;
     	    	y++;
			}
		}  	
	}
	for(int i = 0;i < n;i++)  {
		for(int j = 0;j < n;j++)
        	cout << a[i][j] << " ";
    	cout << endl;
	}
   return 0;
} 
