#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> //.

int32_t n, q;
int32_t f1[200001][26] = {0};
int32_t f2[200001][26] = {0};

void solve() {
    std::cin >> n >> q;
    std::string t1, t2; std::cin >> t1 >> t2;
    
    std::string a = "$"; a += t1;
    std::string b = "$"; b += t2;
    
    for(int32_t i = 1; i < n + 1; i++) {
        std::copy(std::begin(f1[i - 1]), std::end(f1[i - 1]), std::begin(f1[i])); 
        ++f1[i][a[i] - 'a'];
        std::copy(std::begin(f2[i - 1]), std::end(f2[i - 1]), std::begin(f2[i])); 
        ++f2[i][b[i] - 'a'];
    }
    
    int32_t l, r;
    for(int32_t i = 0; i < q; i++) {
        std::cin >> l >> r;
        int32_t cnt = 0;
        
        for(int32_t j = 0; j < 26; j++) {
            int x = f1[r][j] - f1[l - 1][j];
            int y = f2[r][j] - f2[l - 1][j];
            cnt += std::abs(x - y); 
        }
        std::cout << (cnt / 2) << '\n';
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
