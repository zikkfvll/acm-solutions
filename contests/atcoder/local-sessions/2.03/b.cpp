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
    template<typename T,typename ...Args>
    inline void read(T &tmp,Args &...tmps){read(tmp);read(tmps...);}
}

using namespace std;
using namespace fastOI;
const int dx[4] = {0, 1, 0, -1}; 
const int dy[4] = {-1, 0, 1, 0};

il void solve(int H, int W, int N) {
	vector<vector<bool>> e(H, vector<bool>(W, false)); 

	int x = 0, y = 0;
	int d = 0; 

	for (int i = 0; i < N; i++) {
		if (e[y][x]) {
			d = (d + 3) % 4;
			e[y][x] = false; 
		} 
        else {
			d = (d + 1) % 4;
			e[y][x] = true;
		}
		x = (x + dx[d] + W) % W;
		y = (y + dy[d] + H) % H;
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cout << (e[i][j] ? '#' : '.');
		}
		putchar('\n');
	}
}

int h , w , n;
int main() {
    //fre();
    read(h , w , n);
    solve(h,w,n); 
    return 0;
}
