#include<iostream>
using namespace std;

int main(){   
	int a,b,n,i,c=0;   
    cin >> a >> b;		 
    for(n = a;n <= b;n++) 
	{ 
		int k = 0;
    	for(i=2;i < n;i++){
    		if(n % i == 0){
    			k = 1;
				break;
			}
		}
   		if(k == 0)
		{ 	 
			c++;
		}
	}
	cout << c <<endl;
      return 0;
}

