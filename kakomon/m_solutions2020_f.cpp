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
    ll n;
    scanf("%lld", &n);
    vector<pair<ll, ll>> U;
    vector<pair<ll, ll>> Up;
    vector<pair<ll, ll>> Um;
    vector<pair<ll, ll>> R;
    vector<pair<ll, ll>> D;
    vector<pair<ll, ll>> Dp;
    vector<pair<ll, ll>> Dm;
    vector<pair<ll, ll>> L;
    for (int i = 0; i < n; i++)
    {
        ll x, y;
        char type;
        cin >> x >> y >> type;
        if (type == 'U')
        {
            U.push_back({x, y});
            Up.push_back({x-y, x});
            Um.push_back({x+y, x});
        }
        else if (type == 'R')
        {
            R.push_back({y, x});
        }
        else if (type == 'D')
        {
            D.push_back({x, y});
            Dp.push_back({x-y, x});
            Dm.push_back({x+y, x});
        }
        else if (type == 'L')
        {
            L.push_back({y, x});
        }
    }
    sort(U.begin(),U.end());
    sort(Up.begin(),Up.end());
    sort(Um.begin(),Um.end());
    sort(R.begin(),R.end());
    sort(D.begin(),D.end());
    sort(Dp.begin(),Dp.end());
    sort(Dm.begin(),Dm.end());
    sort(L.begin(),L.end());
    ll min_time = numeric_limits<ll>::max();
    for(auto u:U){
        // cout << u.first << "," << u.second << endl;
        auto iter = lower_bound(D.begin(),D.end(),u);
        if (iter != D.end() && iter->first == u.first){
            // cout << iter->first << "," << iter->second << endl;
            min_time = min(min_time,(iter->second - u.second) * 5);
        }
    }
    for(auto r:R){
        auto iter = lower_bound(L.begin(),L.end(),r);
        if (iter != L.end() && iter->first == r.first){
            min_time = min(min_time,(iter->second - r.second) * 5);
        }
    }

    for(auto r:R){
        ll y = r.first;
        ll x = r.second;
        auto iter = lower_bound(Dp.begin(),Dp.end(),make_pair(x-y,x));
        if (iter != Dp.end() && iter->first == x-y){
            min_time = min(min_time, (iter->second - x)*10);
        }
    }

    for(auto r:R){
        ll y = r.first;
        ll x = r.second;
        auto iter = lower_bound(Um.begin(),Um.end(),make_pair(x+y,x));
        if (iter != Um.end() && iter->first == x+y){
            min_time = min(min_time, (iter->second - x)*10);
        }
    }

    for(auto l:L){
        ll y = l.first;
        ll x = l.second;
        auto iter = lower_bound(Up.rbegin(),Up.rend(),make_pair(x-y,x),greater());
        if (iter != Up.rend() && iter->first == x-y){
            min_time = min(min_time, (x - iter->second)*10);
        }
    }

    for(auto l:L){
        ll y = l.first;
        ll x = l.second;
        auto iter = lower_bound(Dm.rbegin(),Dm.rend(),make_pair(x+y,x),greater());
        if (iter != Dm.rend() && iter->first == x+y){
            min_time = min(min_time, (x- iter->second)*10);
        }
    }

    if (min_time == numeric_limits<ll>::max()){
        cout << "SAFE" << endl;
    }else{
        cout << min_time << endl;
    }
    return 0;
}

int main()
{
    // // 整数の入力
    // ll t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
    solve();
    // }
    // cout << flush;
    return 0;
}
