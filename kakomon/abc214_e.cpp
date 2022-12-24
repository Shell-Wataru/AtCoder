#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
using namespace std;
using ll = long long;

int solve()
{
    ll N;
    cin >> N;
    set<pair<ll, ll>> vacants;
    vacants.insert({1000000000,0});
    vector<pair<ll, ll>> queries(N);
    for (int i = 0; i < N; i++)
    {
        ll l, r;
        cin >> l >> r;
        l--;
        queries[i] = {r, l};
    }
    sort(queries.begin(),queries.end());
    for (int i = 0; i < N; i++)
    {
        ll r = queries[i].first;
        ll l = queries[i].second;
        auto iter = vacants.upper_bound({l, numeric_limits<ll>::max()});
        // cout << l << "~" << r << endl;
        if (iter != vacants.end() && r > iter->second)
        {
            // cout << iter->first << "~" << iter->second << endl;
            ll use = max(l, iter->second);
            ll l1 = iter->second;
            ll r1 = use;
            ll l2 = use + 1;
            ll r2 = iter->first;
            vacants.erase(iter);
            if (r1 - l1 > 0)
            {
                vacants.insert({r1,l1});
            }
            if (r2 - l2 > 0)
            {
                vacants.insert({r2, l2});
            }
        }
        else
        {
            // cout << "!!!" << endl;
            // for(auto p:vacants){
            //     cout << p.first << "~" << p.second << endl;
            // }
            cout << "No\n";
            return 0;
        }
    }
    // cout << "!!!" << endl;
    // for(auto p:vacants){
    //     cout << p.first << "~" << p.second << endl;
    // }
    cout << "Yes\n";
    return 0;
}

int main()
{
    // 整数の入力
    ll t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        solve();
    }
    cout << flush;
    return 0;
}
