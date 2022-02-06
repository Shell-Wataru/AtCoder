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
    vector<vector<ll>> indices(26);
    for(int i = 0;i < n;i++){
        indices[A[i] - 'a'].push_back(i);
    }
    string ans(6,'a');
    string s = "";
    answer(indices,ans,s,-1);
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