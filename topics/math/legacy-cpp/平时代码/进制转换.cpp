#include <iostream>
#include <string.h>
#include <ctype.h>
using namespace std;
int p1,p2,k;
char a[10000];
int tren1(char c)
{
	if(isdigit(c)){
		return c-48;
	}	
	else{
		return c-'A'+10; 
	}
}
char tren2(int k)
{
	if(k<=9){
		return k+48;
	}
	else{
		return 'A'+k-10; 
	}
	
}
int p1toten()
{
	int s=0;
	int k=1;
	for(int i=strlen(a)-1 ; i >= 0 ; i--)
	{ 
		s = s + k * tren1(a[i]);
		k *= p1;
		
	}
	return s;
	
}
void tentop2(int k)
{
	if(k == 0){
		return ;
	}
	tentop2(k / p2);
	cout << tren2(k%p2);
	
}
int main()
{
	cin>>p1>>a>>p2;
	k=p1toten();
	tentop2(k);
	return 0;
 } 
