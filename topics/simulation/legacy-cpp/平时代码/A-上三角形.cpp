#include <iostream>
using namespace std;
int main (){
	int i,j,k=1,n;
	int a[101][101]={0};
    cin >> n;
    for(i = 0 ; i <= n ; i++){
    	for(j = i;j <= n ; j++){
			a[i][j] = k;
			k++;
		}
		if(k == n*(n+1)/2){
			break;
		}
		k--;
	}
   for(i=0;i<n;i++)  {
     for(j=0;j<n;j++)
        cout << a[i][j] << " ";
    cout << endl;
   }
   return 0;
} 
