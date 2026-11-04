#include <bits/stdc++.h>
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
        else if(flg==1)putchar('\n');
    }

    template<typename T>
    inline void read(T &ans){
        char ch=getchar();int f=1;ans=0;
        for(;!isdigit(ch);ch=getchar()) ch=='-'?f=-1:f=1;
        for(;isdigit(ch);ch=getchar()) ans=(ans<<3)+(ans<<1)+(ch&15);
        ans*=f;
        return;
    }
    template<typename T,typename ...Args>
    inline void read(T &tmp,Args &...tmps){read(tmp);read(tmps...);}
}

using namespace std;
using namespace fastOI;

const int N=1e5+200,INF=2e5;
struct point
{
	int id,val;
	friend bool operator < (point a,point b){
        return a.val<b.val; 
    }
};
int n,m,x0,la,lb,res;
int h[N],s[N],x[N];
int f[20][N][5],da[20][N][5],db[20][N][5];
double ans=INF*1.0;
multiset<point> q;

il void dpInit() {
    for(int i=1;i<=18;i++)
		for(int j=1;j<=n;j++)
			for(int k=0;k<2;k++)
				if(i==1)
				{
					f[1][j][k]=f[0][f[0][j][k]][1-k];
					da[1][j][k]=da[0][j][k]+da[0][f[0][j][k]][1-k];
					db[1][j][k]=db[0][j][k]+db[0][f[0][j][k]][1-k];	
				}
				else
				{
					f[i][j][k]=f[i-1][f[i-1][j][k]][k];
					da[i][j][k]=da[i-1][j][k]+da[i-1][f[i-1][j][k]][k];
					db[i][j][k]=db[i-1][j][k]+db[i-1][f[i-1][j][k]][k];
				}//3、倍增优化DP
}

il void pre(){
    h[0] = INF;
    h[n+1]=-INF;
	point st;
	st.id = 0,st.val=INF;
	q.insert(st),q.insert(st);
	st.id=n+1,st.val=-INF;
	q.insert(st),q.insert(st);
	for(int i=n;i;--i){
		int ga,gb;
		point now;
		now.id=i,now.val=h[i];
		q.insert(now);
		set<point>::iterator p=q.lower_bound(now);
		p--;
		int lt=(*p).id,lh=(*p).val;
        p++ , p++;
		int ne=(*p).id,nh=(*p).val;
		p--;
		if(abs(nh-h[i])>=abs(h[i]-lh)){
			gb=lt;
			p-- , p--;
			if(abs(nh-h[i])>=abs(h[i]-(*p).val)) ga=(*p).id;
			else ga=ne;
		}
		else {
			gb=ne;
			p++ , p++;
			if(abs((*p).val-h[i])>=abs(h[i]-lh)) ga=lt;
			else ga=(*p).id;
		}
		f[0][i][0]=ga,f[0][i][1]=gb;
		da[0][i][0]=abs(h[i]-h[ga]);
		db[0][i][1]=abs(h[i]-h[gb]);//3、DP初值
	}
    dpInit();
}

il void calc(int s ,int x) {
    int pp = s;
    la=0,lb=0;
    for(int i = 18;i >= 0;i--) {
        if(f[i][pp][0] && la+lb+da[i][pp][0]+db[i][pp][0]<=x) {
			la+=da[i][pp][0];
			lb+=db[i][pp][0];
			pp=f[i][pp][0];
		} 
    }
}

int main() {
    //fre();
    ios::sync_with_stdio(false);
    cin.tie(0) , cout.tie(0); 
    //read(n);
    //for(int i=1;i<=n;i++) read(h[i]);
    //read(x0,m);
    // /for(int i =1;i <= m;++i) read(s[i] , x[i]);
    cin >> n ;
    for(int i=1;i<=n;i++) cin >> h[i];
    cin >> x0 >> m;
    for(int i = 1;i <= m;++i) cin >> s[i] >> x[i];
    pre();
    for(int i=1;i<=n; ++i){
		calc(i,x0);
		double nres=(double)la/(double)lb;
		if(nres<ans) ans=nres , res=i;
		else if(nres==ans && h[res]<h[i]) res=i;
	}
	//print(res,1);
    cout << res << endl;
	for(int i=1;i<=m;i++){
		calc(s[i] , x[i]);
		// print(la,0);
        // print(lb,1);
        cout << la << " " << lb << endl;
	}
    return 0;
}
