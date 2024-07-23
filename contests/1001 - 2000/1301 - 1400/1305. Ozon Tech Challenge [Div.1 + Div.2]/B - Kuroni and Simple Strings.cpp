#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> //.

void solve() {
    std::string s; std::cin >> s;
    
    int16_t n = s.size();
    bool idx[1000] = {0};
    std::queue<int16_t> qu;
    std::stack<int16_t> st;
    
    for(int16_t i = 0; i < n; i++) {
        if(s[i] == '(') qu.push(i);
        if(s[i] == ')') st.push(i);
    }
    
    while(!qu.empty() && !st.empty() && (qu.front() < st.top())){
        idx[qu.front()] = idx[st.top()] = 1;
        qu.pop(); st.pop();
    }
    qu = {}; st = {};
    
    int16_t m = std::count(std::begin(idx), std::end(idx), 1);
    
    if(m == 0) { std::cout << 0; return; }
    
    std::cout << 1 << '\n';
    std::cout << m << '\n';
    for(int16_t i = 0; i < n; i++) {
        if(idx[i] == 1) std::cout << i + 1 << ' ';
    }
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
