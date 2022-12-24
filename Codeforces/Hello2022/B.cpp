#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <bitset>

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

int solve()
{
    ll q;
    cin >> q;
    vector<vector<ll>> ranges(q,vector<ll>(3));
    for(int i = 0;i < q;i++){
        cin >> ranges[i][0] >> ranges[i][1] >> ranges[i][2];
    }
    ll min_l = numeric_limits<ll>::max();
    ll min_l_cost = numeric_limits<ll>::max();
    ll max_r = numeric_limits<ll>::min();
    ll min_r_cost = numeric_limits<ll>::max();
    ll one_min_cost = numeric_limits<ll>::max();
    ll ans = numeric_limits<ll>::max();
    for(int i = 0;i < q;i++){
        if (ranges[i][0] < min_l){
            min_l = ranges[i][0];
            min_l_cost = ranges[i][2];
            one_min_cost = numeric_limits<ll>::max();
        }else if (ranges[i][0] == min_l){
            min_l_cost = min(min_l_cost,ranges[i][2]);
        }
        if (ranges[i][1] > max_r){
            max_r = ranges[i][1];
            min_r_cost = ranges[i][2];
            one_min_cost = numeric_limits<ll>::max();
        }else if (ranges[i][1] == max_r){
            min_r_cost = min(min_r_cost,ranges[i][2]);
        }
        if (ranges[i][0] == min_l && ranges[i][1] == max_r) {
            one_min_cost = min(one_min_cost,ranges[i][2]);
        }
        cout << min(one_min_cost,min_l_cost+min_r_cost) << "\n";
    }
    return 0;
}
int main()
{
    ll t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}
