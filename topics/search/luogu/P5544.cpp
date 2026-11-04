#include <bits/stdc++.h>
using namespace std;
const double delta = 0.99855;
const double MAX_TIME = 0.8;
struct Point {
    int x;
    int y;
    int r;
}human[10005] , build[15];

double resx = 0 , resy = 0, res ,t,r;
int n , m;

double Rcalc(double x,double y,double a,double b) {
    return sqrt((x-a)*(x-a)+(y-b)*(y-b));
}

int calc(double x,double y) {
    int ans = 0;
    double R = r;
    for(int i = 1; i <= n; ++i) {
        double Rt = Rcalc(build[i].x,build[i].y,x,y)-build[i].r; 
        if(Rt < 0) return 0; 
        if(R > Rt) R = Rt; 
    }
    for(int i = 1; i <= m; ++i)
        if(Rcalc(human[i].x,human[i].y,x,y) <= R) 
            ans++;
    return ans;
}

inline void sa() {
    t = 3000;
    while (t > 1e-18) {
        double X = resx + ((rand() << 1) - RAND_MAX) * t;
        double Y = resy + ((rand() << 1) - RAND_MAX) * t;
        double now = calc(X, Y);
        //cout << now  <<endl;
        double newDelta = now - res;
        if(newDelta > 0) {
            resx = X;
            resy = Y;
            res = now;
        }
        else if(exp(-newDelta / t) * RAND_MAX < rand()) {
            resx = X;
            resy = Y;
        }
        t *= delta;
    }
}

inline void solve() {
    resx /= m , resy /= m;
    res = calc(resx, resy);
    sa();
    sa();
    sa();
    sa();
    sa();
    sa();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    srand(20080512);
    cin >> n >> m >> r;
    for(int i = 1;i <= n; ++i)  cin >> build[i].x >> build[i].y >> build[i].r;
    for(int i = 1;i <= m; ++i) {
        cin >> human[i].x >> human[i].y;
        resx += human[i].x;
        resy += human[i].y;
    }
    solve();
    cout <<(int) res;
    return 0;
}
