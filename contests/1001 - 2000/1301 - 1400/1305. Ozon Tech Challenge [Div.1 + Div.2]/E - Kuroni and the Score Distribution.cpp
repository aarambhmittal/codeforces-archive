#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> //.

int32_t n, m;
int32_t maxm[5001] = {0};

void solve() {
    std::cin >> n >> m;
    
    std::function<void()> precompute = [&]() {
        for(size_t i = 3; i < 5001; i++) {
            int32_t t = (i & 1)? (i - 1) / 2: i / 2 - 1;
            maxm[i] = t + maxm[i - 1];
        }
    };
    precompute();
    
    if(maxm[n] < m) { std::cout << -1; return; }
    
    int32_t lo = 1, hi = n + 1, idx = -1;
    while(lo < hi) {
        int32_t mid = lo + (hi - lo) / 2;
        if(maxm[mid] > m) { 
            hi = mid;
        }
        else {
            idx = mid; 
            lo = mid + 1;
        }
    }
    
    std::vector<int32_t> v;
    for(int32_t i = 1; i <= idx; i++) v.push_back(i);

    int32_t rn = n - idx, rm = m - maxm[idx];
    if(rn > 0) {
        int32_t sz = v.size(); // idx
        if(rm > 0) { 
            v.push_back(v[sz - 1] + v[sz - 2*rm - 1]);
            --rn;
        }
        
        int32_t mx = v.back();
        for(int32_t i = 1; i <= rn; i++) {
            v.push_back(v.back() + mx + 1);
        }
    }
    
    for(int32_t& i: v) std::cout << i << ' ';
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
