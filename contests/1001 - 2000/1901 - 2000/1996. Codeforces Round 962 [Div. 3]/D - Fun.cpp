#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> //.

int32_t n, x;
int64_t ans;

void solve() {
    std::cin >> n >> x;
    
    ans = 0;
    for(int32_t a = 1; a <= (n - 1) / 2 && a <= x - 2; a++) {
        for(int32_t b = 1; a * b + a + b <= n && a + b <= x - 1; b++) {
            int32_t c1 = (n - (a * b)) / (a + b);
            int32_t c2 = x - a - b;
            ans += std::min(c1, c2);
        }
    }
    
    std::cout << ans << '\n';
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

// g++ -std=c++20 <filename>.cpp
