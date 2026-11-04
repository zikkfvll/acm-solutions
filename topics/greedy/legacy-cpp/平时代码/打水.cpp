#include<iostream>
#include <algorithm>
#include<iomanip>
using namespace std;
struct Person{
	int t;
	int no;
}a[1005];
bool cmp(Person p1,Person p2){
	return p1.t<p2.t;
}
int main(){
	int n;
	float m;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].t;
		a[i].no=i;
	}
	double sum=0;
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		cout<<a[i].no<<' ';
		sum+=a[i].t*(n-i);
	}
	m = sum / n; 
	cout<<endl;
	cout<<setiosflags(ios::fixed)<<setprecision(2)<<m<<endl; 
}
