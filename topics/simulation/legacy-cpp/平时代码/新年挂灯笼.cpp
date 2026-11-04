#include<iostream>
using namespace std;
int main(){
	int t,m,n,i,j,k;
	cin>>t;
	for(m = 1;m<=t;m++){
		while(scanf("%d",&n)!=EOF){
			for(i = 1; i <= n ;i++){
				for(j = 1;j <= n-i;j++)
					cout <<" ";
				for(k = 1; k<2*i+n-1;k++)
					cout<<"*";
				cout<<"\n";
				}
				for(i = n+1;i<=2*n-1;i++){
					for(j = 1;j <= i-n;j++)
						cout<<" ";
					for(k =1;k<2*(2*n-i)+n-1;k++)
						cout<<"*";
					cout<<"\n";
				}
				break;
			}
		}
	} 

