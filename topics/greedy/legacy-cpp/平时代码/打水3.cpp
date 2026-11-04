#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

struct Date {
	int id;
	int ti;
};

bool cmp(Date a,Date b){
	return a.ti < b.ti;
}

int main(){
	Date a[1100];
	int n;
	long long s = 0 , b = 0;
	
	
	cin >> n;
	for(int i = 1;i <= n; i++){
		a[i].id = i;
		cin >> a[i].ti;
	} 
	
	stable_sort(a + 1, a+n+1 , cmp);
	
	for(int i= 1 ; i <= n;i++){
		s +=b;
		b += a[i].ti;
	}
	
	for(int i = 1;i <= n;i++){
	cout << a[i].id << " " ;  
	}
	cout <<endl;
    cout << fixed << setprecision(2) << s * 1.0 / n;
    return 0 ;
}
