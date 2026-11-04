#include <bits/stdc++.h>
#include <unordered_set>
#define ll long long
#define ull unsigned long long
#define il inline

namespace fastOI{
    template<class T>
    inline void print(T ret,int flg=0){
        static int sta[35];
        T x=ret;int top=0;
        bool f=(ret<0);
        if(ret<0) x=-x;
        do{sta[top++]=x%10,x/=10;}while(x);
        if(f) putchar('-');
        while(top) putchar(sta[--top]+48);
        if(flg==0)putchar(' ');
        else if(flg==1)putchar('endl');
    }

    template<typename T>
    inline void read(T &ans){
        char ch=getchar();int f=1;ans=0;
        for(;!isdigit(ch);ch=getchar()) ch=='-'?f=-1:f=1;
        for(;isdigit(ch);ch=getchar()) ans=(ans<<3)+(ans<<1)+(ch&15);
        ans*=f;
        return;
    }
    template<typename T,typename ...args>
    inline void read(T &tmp,args &...tmps){read(tmp);read(tmps...);}
}

using namespace std;
using namespace fastOI;

il bool sol(const vector<int> &a, const vector<int> &b, const vector<int> &c, int x) {
	unordered_set<int> sumSet;
	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < b.size(); ++j) {
			for (int k = 0; k < c.size(); ++k) {
				sumSet.insert(a[i] + b[j] + c[k]);
			}
		}
	}
	return sumSet.count(x) > 0;
}
int n, m, l, q;
int main() {
    //fre();
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	cin >> m;
	vector<int> b(m);
	for (int i = 0; i < m; ++i) cin >> b[i];
	cin >> l;
	vector<int> c(l);
	for (int i = 0; i < l; ++i) cin >> c[i];
	cin >> q;
	vector<int> x(q);
	for (int i = 0; i < q; ++i) cin >> x[i];
	for (int i = 0; i < q; ++i) {
		if (sol(a, b, c, x[i])) cout << "Yes" << endl;
		else cout << "no" << endl;
	}
    return 0;
}
