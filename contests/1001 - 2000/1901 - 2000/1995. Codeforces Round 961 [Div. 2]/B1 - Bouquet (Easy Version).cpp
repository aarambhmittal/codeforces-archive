#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> //.

int32_t n;
int64_t m, ans;
std::map<int32_t, int32_t> mp;
std::map<int32_t, int32_t> :: iterator it;

void solve() {
    std::cin >> n >> m;
    mp.clear();
    
    for(size_t i = 0; i < n; i++) {
        int32_t t; std::cin >> t; ++mp[t];
    }
    
    ans = 0;
    for(it = mp.begin(); it != mp.end(); ++it) {
        int64_t curr = it->first;
        int64_t kcurr = std::min((int64_t) mp[curr], m / curr);
        
        ans = std::max(ans, kcurr * curr);
        
        if(mp.count(curr - 1)) {
            int64_t prev = curr - 1;
            int64_t kprev;
            for(int64_t i = 0; i <= kcurr; i++) {
                kprev = std::min((int64_t) mp[prev], (m - i * curr) / prev);
                ans = std::max(ans, i * curr + prev * kprev);
            }
        }
        
        if(mp.count(curr + 1)) {
            int64_t next = curr + 1;
            int64_t knext;
            for(int64_t i = 0; i <= kcurr; i++) {
                knext = std::min((int64_t) mp[next], (m - i * curr) / next);
                ans = std::max(ans, i * curr + next * knext);
            }
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
