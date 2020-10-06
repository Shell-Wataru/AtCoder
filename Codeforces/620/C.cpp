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

struct customer{
    ll t,l,h;
};
int solve()
{
    ll n,m;
    cin >> n >> m;
    set<ll> unique_times;
    map<ll,ll> zipped_times;
    map<ll,ll> unzipped_times;
    vector<customer> customers;
    for (size_t i = 0; i < n; i++)
    {
        customer c;
        cin >> c.t >> c.l >> c.h;
        unique_times.insert(c.t);
        customers.push_back(c);
    }
    ll time_index = 0;
    for(auto t:unique_times){
        zipped_times[t] = time_index;
        unzipped_times[time_index] = t;
        time_index++;
    }
    vector<ll> l_temps(unique_times.size(), - BASE_NUM);
    vector<ll> h_temps(unique_times.size(), BASE_NUM);
    for(auto c: customers){
        l_temps[zipped_times[c.t]] = max(l_temps[zipped_times[c.t]],c.l);
        h_temps[zipped_times[c.t]] = min(h_temps[zipped_times[c.t]],c.h);
    }
    ll controllable_l = m;
    ll controllable_h = m;
    ll last_t = 0;
    for(int i = 0;i < unique_times.size();i++){
        ll time_delta = unzipped_times[i] - last_t;
        last_t = unzipped_times[i];
        controllable_h = controllable_h + time_delta;
        controllable_l = controllable_l - time_delta;
        // cout << "time:" << unzipped_times[i] <<  endl;
        // cout << controllable_l << "~" << controllable_h << endl;
        // cout << l_temps[i] << "~" << h_temps[i] << endl;
        if (h_temps[i] < l_temps[i] || controllable_h < l_temps[i] || h_temps[i] < controllable_l){
            cout << "NO" << endl;
            return 0;
        }else{
            controllable_h = min(h_temps[i],controllable_h);
            controllable_l = max(l_temps[i],controllable_l);
        }
        // cout << controllable_l << "~" << controllable_h << endl;

    }
    cout << "YES" << endl;
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
    return 0;
}
