#include <iostream>
using namespace std;
int main (){
	int k=1,n;
	int a[110][110]={0};
    cin >> n;
    for(int j = 0 ; j < n ; j++){
    	for(int i = j;i < n ; i++){
			a[i][j] = k;
			k++;
		}	
	}
	for(int i = 0;i < n;i++)  {
		for(int j = 0;j < n;j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	return 0;
} 
