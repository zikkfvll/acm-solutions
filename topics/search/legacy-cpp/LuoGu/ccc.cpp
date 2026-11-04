#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define MOD 19940417
#define re register
using namespace std;

template<typename T>
inline void read(T &ans){
	char ch=getchar(); int f=1;ans=0;
	for(;!isdigit(ch);ch=getchar()) ch=='-'?f=-1:f=1;
	for(;isdigit(ch);ch=getchar()) ans=(ans<<3)+(ans<<1)+(ch&15);
	ans*=f;
	return;
}
template<typename T,typename ...Args>
inline void read(T &tmp,Args &...tmps){read(tmp);read(tmps...);}

template<class T>
inline void print(T ret,int flg=0){
	static  int sta[35];
	T x=ret; int top=0;
	bool f=(ret<0);
	if(ret<0) x=-x;
	do{sta[top++]=x%10,x/=10;}while(x);
	if(f) putchar('-');
	while(top) putchar(sta[--top]+48);
	if(flg==0)putchar(' ');
	else if(flg==1)putchar('endl');
}


void c(vector<long long> &arr, vector<long long> &data, re long long st,re long long ed,re long long in, re long long r, re long long &sum) {
    if (in == r) {
        re long long pp(1);
        for (re long long j(0); j<r; ++j)
            pp *= data[j];
        sum += pp;
        return;
    }
    for (re long long i(st); i <= ed && ed-i+1 >= r-in; ++i) {
        data[in] = arr[i];
        c(arr, data, i+1, ed, in+1, r, sum);
    }
}

void pc(vector< long long> &arr, re long long n,re long long r) {
    re long long sum(0);
    vector<long long> data(r);
    c(arr, data, 0, n - 1, 0, r, sum);
	print((sum + MOD) % MOD);
	putchar('\n');
}

int main(){
	re int n, q;
	re long long a[50005];
	char op;

	read(n, q);
	for(re int i(1); i <= n; ++i) read(a[i]);
	for(re int i (1); i <= q; ++i){
		scanf(" %c", &op);
		re int a2 , b , c;
		if(op == 'I') {
			read(a2, b, c);
			for (int i(a2); i <= b; ++i)
				a[i] = a[i] + c;
		}
		else if(op == 'R') {
			read(a2, b);
			for (int i(a2); i <= b; ++i)
				a[i] = -a[i];
		}
		else if(op == 'Q') {
			read(a2, b, c);
			vector<long long> arr;
			for(re int i(a2); i <= b; ++i)
				arr.push_back(a[i]);
			re int len(arr.size());
			pc(arr, len, c);
		}
	}
	return 0;
}

