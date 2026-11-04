#include<bits/stdc++.h>
using namespace std;
int n,cnt;
string a;

namespace work1{
	inline bool ic(string a){
    	while(a.length()){
     	   bool flag(true);
     	   for(int i(0) ; i < a.length(); ++i){
      	      if(a[i] == a[i + 1]){
      	          string now = "";
       	         flag = false;
        	        for(int j(0);j <= a.length();j++){
         	           if(j != i && j != i + 1) now += a[j];
          	      }
         	       a = now;
         	   }
        	}
       		if(flag == true) return false;
   		}	
    	return a.length() == 0;
	}
	
	int cnt(0);
	
	inline void work() {
		for(int i(2);i <= n;i += 2){
        	for(int j(0);j < a.length();j++){
         	    if(j + i > n) break;
         	    if(ic(a.substr(j,i))) 
					cnt++;
        	}
    	}
    	cout << cnt;
	}
}

int main(){
	ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0); 
    cin >> n >> a;
    work1::work();
    return 0;
}
