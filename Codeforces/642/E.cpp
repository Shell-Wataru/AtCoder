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

ll sub_solve(ll total_ones,ll one_count,vector<ll> &data){
    // for(auto d: data){
    //     cout << d;
    // }
    // cout << endl;
    vector<ll> diffs;
    diffs.push_back(0);
    ll current = 0;
    for(int i = 0;i < data.size();i++){
        if(data[i] == 0){
            current--;
        }else{
            current++;
        }
        diffs.push_back(min(diffs.back(),current));
    }
    current = 0;
    ll min_move = total_ones - one_count + ((ll)(data.size()) - one_count) + diffs.back();
    // cout << min_move << endl;
    for(int i = data.size() - 1;i >=0 ;i--){
        if(data[i] == 0){
            current--;
        }else{
            current++;
        }
        // cout << i <<":" << current << q.top().first << " "<< q.top().second <<endl;
        min_move = min(min_move,total_ones - one_count + ((ll)data.size() - one_count) + diffs[i] + current);
    }
    return min_move;
}
int solve()
{

    ll n, k;
    cin >> n >> k;
    vector<vector<ll>> indexes(k);
    vector<ll> one_counts(k,0);
    string S;
    cin >> S;
    ll total_ones = 0;
    for (int i = 0; i < n; i++)
    {
        if (S[i] == '1'){
            indexes[i % k].push_back(1);
            total_ones++;
            one_counts[i%k]++;
        }else{
            indexes[i % k].push_back(0);
        }
    }
    ll min_moves = INT_MAX;
    for(int i = 0;i < k;i++){
        min_moves =min(min_moves,sub_solve(total_ones,one_counts[i],indexes[i]));
    }
    cout << min_moves << endl;
    return 0;
}
int main()
{
    int t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}