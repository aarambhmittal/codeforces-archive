#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> //.

int32_t n, a[100], b[100];

void solve() {
    std::cin >> n;
    
    for(size_t i = 0; i < n; i++) std::cin >> a[i];
    for(size_t i = 0; i < n; i++) std::cin >> b[i];
    
    std::sort(std::begin(a), std::begin(a) + n);
    std::sort(std::begin(b), std::begin(b) + n);
    
    for(size_t i = 0; i < n; i++) std::cout << a[i] << ' ';
    std::cout << '\n';
    for(size_t i = 0; i < n; i++) std::cout << b[i] << ' ';
    std::cout << '\n';
}

signed main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);
    
    #ifndef ONLINE_JUDGE
        freopen("input", "r", stdin);
        freopen("output", "w", stdout);
    #endif
    
    int tst; std::cin >> tst;
    while(tst--) solve();
                
    return 0;
}
