#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> //.

int32_t n, k, ans;

void solve() {
    std::cin >> n >> k;
        
    if(n >= k) { std::cout << std::min(1, k) << '\n'; return; }
    
    ans = 1; k -= n; --n;
    while(true) {
        if(k <= 0) break;
        
        if(k - n > 0) { k -= n; ++ans; }
        else { ++ans; break; }
        if(k - n > 0) { k -= n; ++ans; }
        else { ++ans; break; }
        --n;
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
