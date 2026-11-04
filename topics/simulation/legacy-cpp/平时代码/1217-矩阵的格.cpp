#include <iostream>
using namespace std;
int main (){
	int n;
    cin >> n;
    for(int k = 2;k <= n*2; k++){
    	for(int i = n; i >= 1 ; i--){
    		int j = k-i;
    		if(i >= 1 &&i <= n && j >= 1&&j <= n){
    			cout<< "("<<i<<","<<j<<")";
			}
		}
		cout<< endl;
	}
   return 0;
} 
