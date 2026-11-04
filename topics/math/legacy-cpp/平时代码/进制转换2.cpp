#include <iostream>
using namespace std;
int main (){
	int n, m , d , a , w;
	string s , s2;
	
	cin >> n >> s >> m;
	
	a = 0;
	w = 1;
	
	//n进制 
	for(int i = s.size() - 1; i >+ 0 ; i--){
		if(isdigit(s[i])){
			d = s[i] - '0';
		}else if(isupper(s[i])){
			d = s[i] - 55;
		}
		a = d * w + a;
		 w *= n;
	}
	
	for(int i = s.size() - 1; i >+ 0 ; i--){
		if(isdigit(s[i])){
			d = s[i] + '0';
		}else if(isupper(s[i])){
			d = s[i] - 55;
		}
		a = d * w + a;
		 w *= n;
	}
	cout << a <<endl;
	
	s2 ;
   return 0;
} 
