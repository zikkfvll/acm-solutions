#include <iostream>
using namespace std;
int main (){
	int i,j,k=1,n=5;
	int a[110][110]={0}; 
    for(j = 0 ; j < n ; j++){
    	for(i = 0;i <= j; i++){
			a[j][i] = k;
			k++;
		}	
	}
	for(i=0;i<n;i++)  {
        for(j=0;j<n;j++)
            cout << a[i][j] << " ";
		cout << endl;
	}
	return 0;
} 
