#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> //.

using float64_t = double;

int32_t n;
float64_t err = 1e-9;
std::vector<float64_t> arr;

void solve() {
    std::cin >> n;
    arr.resize(n);
    
    for(float64_t& i: arr) std::cin >> i;
    
    std::reverse(arr.begin(), arr.end());
    while(!arr.empty() && (arr.back() == 1.0)) {
        arr.pop_back();
    }
    std::reverse(arr.begin(), arr.end());
    n = arr.size();
    
    for(float64_t& i: arr) {
        if(i == 1.0) { 
            std::cout << -1 << '\n'; return;
        }
    }
  
    for(float64_t& i: arr) i = log(log(i));
    
    int64_t ans = 0;
    for(int32_t i = 1; i < n; i++) {
        float64_t d = arr[i - 1] - arr[i];
        if(d > err) {
            int32_t cnt = 1 + (d - err) / log(2);
            ans += cnt;
            arr[i] += cnt * log(2);
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
