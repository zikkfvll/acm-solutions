#include<bits/stdc++.h>
using namespace std;
char c;
int l ,r;
int main() {
	do{
		cin >> c;
		if(c=='(') ++l;
		if(c == ')') ++r;
		if(r>l) { cout<<"NO";  return 0;}
		
	}while(c!='@');
	if(l==r) cout<<"YES";
	else cout<<"NO";
	return 0;
}
