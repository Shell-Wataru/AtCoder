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

int main()
{
    // 整数の入力
    string s,t;
    cin >> s >> t;
    vector<vector<ll>> char_indexes(26,vector<ll>(0));
    for(int i = 0;i < s.size();i++){
        char_indexes[s[i] - 'a'].push_back(i);
    }
    ll char_index = -1;
    ll ans = 0;
    for(int i = 0;i < t.size();i++){
        if (char_indexes[t[i] - 'a'].empty()){
            cout << -1 << endl;
            return 0;
        }
        auto itr = upper_bound(char_indexes[t[i] - 'a'].begin(),char_indexes[t[i] - 'a'].end(),char_index);
        if (itr != char_indexes[t[i] - 'a'].end()){
            char_index = *itr;
        }else{
            char_index = char_indexes[t[i] - 'a'][0];
            ans += s.size();
        }
    }
    cout << ans + char_index + 1<< endl;
    return 0;
}