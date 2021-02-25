#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;

bool can_make(ll x, vector<ll> &candidates){
    vector<set<ll>> dp(2);
    dp[0].insert(0);
    for(int i = 0;i< candidates.size();i++){
        ll currnet_index = i % 2;
        ll next_index = (i+1) % 2;
        dp[next_index].clear();
        for(auto &c:dp[currnet_index]){
            dp[next_index].insert(c + candidates[i]);
            dp[next_index].insert(c - candidates[i]);
        }
    }

    return dp[candidates.size() % 2].find(x) != dp[candidates.size() % 2].end();
}
int main()
{
    // 整数の入力
    string s;
    cin >> s;
    ll x,y;

    cin >> x >> y;
    vector<ll> vertical_candidates;
    vector<ll> horizontal_candidates;
    bool is_first = true;
    bool horizontal = true;
    ll continues = 0;
    for(auto c:s){
        if (c == 'F'){
            continues++;
        }else{
            if (is_first){
                x -= continues;
            }else if(horizontal){
                horizontal_candidates.push_back(continues);
            }else{
                vertical_candidates.push_back(continues);
            }
            is_first = false;
            horizontal = !horizontal;
            continues = 0;
        }
    }
    if (is_first){
        x -= continues;
    }else if(horizontal){
        horizontal_candidates.push_back(continues);
    }else{
        vertical_candidates.push_back(continues);
    }
    // for(auto c:horizontal_candidates){
    //     cout << c << ",";
    // }
    // cout << endl;
    // for(auto c:vertical_candidates){
    //     cout << c << ",";
    // }
    // cout << endl;
    if (can_make(x,horizontal_candidates) &&can_make(y,vertical_candidates)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}