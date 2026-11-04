#include <iostream>
using namespace std;
int main (){
	int n;
    cin >> n;
    for(int k = 1 - n;k <= n-1; k++){
    	for(int i = n; i >= 1 ; i--){
    		int j = i - k;
    		if(i >= 1 &&i <= n && j >= 1&&j <= n){
    			cout<< "("<<i<<","<<j<<")";
			}
		}
		cout<< endl;
	}
   return 0;
} 
