#include<iostream>
using namespace std;
int main(){
	int i,j=0,n;
	int a[101][101]={0};
    cin >> n;
	for(i=1;i<=n;i++){
	    for(j=1;j<=(5-i);j++){
    		cout<<" ";
    	}
    	for(j=1;j<=(2*i-1);j++){
	    	cout<<"*";
	    }
	    cout<<endl;
	}
	return 0;
   for(i=0;i<n;i++)  {
     for(j=0;j<n;j++)
        cout << a[i][j] << " ";
    cout << endl;
   }
		cout<<endl;
	}
} 


