//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("Ofast")


#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define re register
#define il inline
#define N 1000010
#define MOD 998244353
#define esp 1e-8
#define INF 999999999999999999
#define rep(x, y, z) for(int x = (y); x <= (z); ++x)
#define per(x, y, z) for(int x = (y); x >= (z); --x)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define freOI(Name) do {freopen(Name".in", "r", stdin); freopen(Name".out", "w", stdout);} while(false)
#define pll pair<ll,ll>
#define mkp(x,y) make_pair(x,y)
#define i128 __int128
#define lowbit(x) ((x)&(-(x)))
#define lc (u<<1)
#define rc (u<<1|1)
#define spa << " " <<
#define fi first
#define se second
#define endl '\n'
#define _ 0

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


il void fre(){
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
}

int main() {
    //freOI(Name);
    //fre();
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);cout.tie(nullptr);
    int n;
    cin >> n;
    while (n--) {
        string name, s, da;
        int flag;
        cin >> name >> s >> da >> flag;
        if (flag == 1) {
            cout << "gdut_" << name spa s spa da << endl;
        }
    }
    return ~~(0 ^ _ ^ 0);
}
/*


M题：输入描述：输入格式 第一行包含一个整数n（1≤n≤50），
表示队伍数量。 接下来n行，每行包含四项： 
队伍名 赛站名 比赛日期 报名结果 
其中： • 队伍名由大小写英文字母组成，长度不超过30。
         所有队伍名两两不同。 
• 赛站名由小写英文字母组成，长度不超过10。 
• 比赛日期的格式为YYYY-MM-DD，且是合法日期。 
• 报名结果为1或0：1表示报名成功，0表示报名失败。 
保证每支队伍在输入中恰好出现一次 (广播消息，勿回^_^)

*/