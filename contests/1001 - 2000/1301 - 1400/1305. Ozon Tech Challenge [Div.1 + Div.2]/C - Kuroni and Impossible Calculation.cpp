#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> //.

void solve() {
    int32_t n, m; std::cin >> n >> m;
    
    int32_t a[200000];
    for(size_t i = 0; i < n; i++) std::cin >> a[i];
    
    if(n > m) { std::cout << 0; return; }
    
    int64_t ans = 1;
    for(size_t i = 0; i < n - 1; i++) {
        for(size_t j = i + 1; j < n; j++) {
            ans = ((ans % m) * (std::abs(a[i] - a[j]) % m)) % m;
        }
    }
    std::cout << (ans + m) % m;
    
}

signed main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);
    
    #ifndef ONLINE_JUDGE
        freopen("input", "r", stdin);
        freopen("output", "w", stdout);
    #endif
    
    int tst = 1;
    while(tst--) solve();
                
    return 0;
}

// g++ -std=c++20 <filename>.cpp
