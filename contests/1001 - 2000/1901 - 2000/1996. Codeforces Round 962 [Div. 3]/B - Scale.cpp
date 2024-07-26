#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> //.

int32_t n, k;
char grid[1000][1000];
char bloc[1000][1000];

void solve() {
    std::cin >> n >> k;
    
    for(int32_t i = 0; i < n; i++) {
        for(int32_t j = 0; j < n; j++) {
            std::cin >> grid[i][j];
        }
    }
    
    // copy row
    int32_t row = 0;
    for(int32_t i = 0; i < n; i += k) {
        for(int32_t j = 0; j < n; j++) {
            bloc[row][j] = grid[i][j]; 
        }
        ++row;
    }

    // skip col
    for(int32_t i = 0; i < row; i++) {
        for(int32_t j = 0; j < n; j += k) {
            std::cout << bloc[i][j];
        }
        std::cout << '\n';
    }
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
