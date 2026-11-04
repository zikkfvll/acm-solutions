#include <bits/stdc++.h>
int n, na, nb;
int a[205], b[205], cnta = 0, cntb = 0;
int vs[5][5] = {{0, 0, 1, 1, 0}, {1, 0, 0, 1, 0}, {0, 1, 0, 0, 1}, {0, 0, 1, 0, 1}, {1, 1, 0, 0, 0}};
int main(){
    std::cin >> n >> na >> nb;
    for (int i = 0; i < na; ++i) std::cin >> a[i];
    for (int i = 0; i < nb; ++i) std::cin >> b[i];
    for (int i = 0; i < n; ++i) cnta += vs[a[i % na]][b[i % nb]], cntb += vs[b[i % nb]][a[i % na]];
    std::cout << cnta << " " << cntb << std::endl;
    return 0;
}