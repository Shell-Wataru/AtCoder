#include <iostream>
#include <bitset>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

ll vertical(ll H,ll W,vector<string> &G){
    unordered_set<bitset<1000>> patterns;
    for(int i = 0;i < H;i++){
        bitset<1000> current;
        for(int j = 0;j < W;j++){
            if (G[i][j] == '#'){
                current.set(j);
            }
        }
        if (i == 0 || i == H-1){
            current.set(0);
            current.set(W-1);
        }
        vector<bitset<1000>> removes;
        for(auto p:patterns){
            if ( (p & current).any()){
                removes.push_back(p);
                current |= p;
            }
        }
        for(auto r:removes){
            patterns.erase(r);
        }
        if (current.any()){
            patterns.insert(current);
        }
    }
    ll ans = -1;
    bitset<1000> ans_pattern;
    for(auto p:patterns){
        ans_pattern |= p;
        ans++;
    }
    return ans + (W- ans_pattern.count());
}

ll horizontal(ll H,ll W,vector<string> &G){
    unordered_set<bitset<1000>> patterns;
    for(int i = 0;i < W;i++){
        bitset<1000> current;
        for(int j = 0;j < H;j++){
            if (G[j][i] == '#'){
                current.set(j);
            }
        }
        if (i == 0 || i == W-1){
            current.set(0);
            current.set(H-1);
        }
        vector<bitset<1000>> removes;
        for(auto p:patterns){
            if ( (p & current).any()){
                removes.push_back(p);
                current |= p;
            }
        }
        for(auto r:removes){
            patterns.erase(r);
        }
        if (current.any()){
            patterns.insert(current);
        }
    }
    ll ans = -1;
    bitset<1000> ans_pattern;
    for(auto p:patterns){
        ans_pattern |= p;
        ans++;
    }
    return ans + (H- ans_pattern.count());
}
int solve()
{
    ll H,W;
    cin >> H >> W;
    vector<string> G(H);
    for(int i = 0;i < H;i++){
        cin >> G[i];
    }
    cout << min(vertical(H,W,G),horizontal(H,W,G)) << endl;
    return 0;
}

int main()
{
    // cout << "!" << endl;
    // 整数の入力
    // ll t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
    solve();
    // }
    // cout << flush;
    return 0;
}
