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

int solve()
{
    ll n;
    scanf("%lld",&n);
    string S1;
    string S2;
    cin >> S1 >> S2;
    vector<pair<ll,ll>> diffs;
    ll total = 0;
    for(int i = 0;i < n;i++){
        ll diff = -1;
        if (S1[i] == '0' && S2[i] == '1'){
            diff = 0;
            total--;
        }else if (S1[i] == '1' && S2[i] == '0'){
            diff = 1;
            total++;
        }
        if (diff != -1){
            if (diffs.empty() || diffs.back().first != diff){
                diffs.push_back({diff,1});
            }else{
                diffs.back().second++;
            }
        }
    }

    if (total != 0){
        cout << -1 << endl;
    }else if (diffs.size() ==0){
        cout << 0 << endl;
    }else {
        ll ans = 0;
        while(diffs.size() > 0){
            if (diffs.back().first == diffs.front().first){
                diffs.front().second += diffs.back().second;
                diffs.pop_back();
            }
            ll min_continue = 1e9;
            for(auto p:diffs){
                min_continue = min(min_continue,p.second);
            }
            // cout << min_continue << endl;
            ans += min_continue;
            vector<pair<ll,ll>> new_diffs;
            for(int i = 0;i < diffs.size();i++){
                ll new_continue = diffs[i].second - min_continue;
                if (new_continue > 0){
                    if (new_diffs.empty() || new_diffs.back().first != diffs[i].first){
                        new_diffs.push_back({diffs[i].first,new_continue});
                    }else{
                        new_diffs.back().second += new_continue;
                    }
                }
            }
            diffs = new_diffs;
        }
        cout << ans << endl;
    }
    return 0;
}
int main()
{
    // int t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
        solve();
    // }
    return 0;
}