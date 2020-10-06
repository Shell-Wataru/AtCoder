#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

int diffs(vector<string> substrings,int k ,int i){
    map<char,ll> counts;
    for(auto s:substrings){
        counts[s[i]]++;
        if (i != k - i - 1){
            counts[s[k - i - 1]]++;
        }
    }
    ll max_counts = 0;
    for(auto p:counts){
        max_counts = max(max_counts,p.second);
    }
    if (i != k - i - 1){
        return substrings.size() * 2 - max_counts;
    }else{
        return substrings.size() - max_counts;
    }
}

int solve()
{
    ll n,k;
    cin >> n >> k;
    string S;
    cin >> S;
    vector<string> substrings;
    for(int i = 0;i < n/k;i++){
        substrings.push_back(S.substr(k * i,k));
    }
    ll total = 0;
    for(int i = 0;i < (k+1)/2;i++){
        total += diffs(substrings,k,i);
    }
    cout << total << endl;
    return 0;
}
int main()
{
    // 整数の入力
    // ll t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
        solve();
    // }
    return 0;
}
