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

bool answer(vector<vector<ll>> &indices, string &ans, string &s,ll index){
    for(int i = 0;i < 26;i++){
        if (ans.size() <= s.size()+1){
            return true;
        }
        s += 'a' + i;
        auto iter  = upper_bound(indices[i].begin(),indices[i].end(),index);
        if (iter == indices[i].end()){
            ans = s;
        }else{
            answer(indices,ans,s,*iter);
        }
        s.pop_back();
    }
    return true;
}

int solve()
{
    string A;
    cin >> A;
    ll n = A.size();
    vector<vector<ll>> lengths(n+1,vector<ll>(26,0));
    for(int i = n-1;i >= 0;i--){
        for(int j = 0;j < 26;j++){
            if (j != A[i] - 'a'){
                lengths[i][j] = lengths[i+1][j];
            }
        }
        lengths[i][A[i] - 'a'] = numeric_limits<ll>::max();
        for(int j = 0;j < 26;j++){
            lengths[i][A[i] - 'a'] = min(lengths[i][A[i] - 'a'],lengths[i+1][j] + 1);
        }
    }
    // for(int i = 0;i < 26;i++){
    //     cout << (char)('a' + i) << ":" << lengths[0][i] << endl;
    // }
    string ans;
    for(int i = 0;i <= n;i++){
        if (ans.empty() || A[i-1] == ans.back()){
            ll min_length = numeric_limits<ll>::max();
            char min_char;
            for(int j = 0;j < 26;j++){
                if (lengths[i][j] < min_length){
                    min_char = 'a' + j;
                    min_length = lengths[i][j];
                }
            }
            ans += min_char;
        }
    }
    cout << ans << endl;
    return 0;
}

int main()
{
    // ll t;
    // cin >> t;
    // for(int i = 0;i < t;i++){
    solve();
    // }
    cout << flush;
    return 0;
}