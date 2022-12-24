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
#include <set>
#include <unordered_map>
using namespace std;
using ll = long long;

ll solve()
{
    ll N;
    cin >> N;
    vector<ll> V(N + 1);
    vector<ll> W(N + 1);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &V[i + 1]);
        scanf("%lld", &W[i + 1]);
    }
    ll split = 12;
    vector<vector<pair<ll, ll>>> DP(min((1ll << split) - 1, N) + 1);
    DP[0] = {{0, 0}};
    for (int i = 1; i <= min((1ll << split) - 1, N); i++)
    {
        vector<pair<ll, ll>> new_values;
        for (auto &p : DP[i / 2])
        {
            if (p.first + W[i] <= 100000)
            {
                new_values.push_back({p.first + W[i], p.second + V[i]});
            }
        }
        DP[i] = {{0, 0}};
        ll before_index = 0;
        ll current_index = 0;
        while (before_index < DP[i / 2].size() || current_index < new_values.size())
        {
            if (before_index < DP[i / 2].size() && DP[i / 2][before_index].second <= DP[i].back().second)
            {
                before_index++;
            }
            else if (current_index < new_values.size() && new_values[current_index].second <= DP[i].back().second)
            {
                current_index++;
            }
            else if (before_index < DP[i / 2].size() && current_index < new_values.size())
            {
                if (DP[i / 2][before_index].first < new_values[current_index].first)
                {
                    DP[i].push_back(DP[i / 2][before_index]);
                    before_index++;
                }
                else if (DP[i / 2][before_index].first > new_values[current_index].first)
                {
                    DP[i].push_back(new_values[current_index]);
                    current_index++;
                }
                else if (DP[i / 2][before_index].second < new_values[current_index].second)
                {
                    DP[i].push_back(new_values[current_index]);
                    current_index++;
                    before_index++;
                }
                else if (DP[i / 2][before_index].second > new_values[current_index].second)
                {
                    DP[i].push_back(DP[i / 2][before_index]);
                    current_index++;
                    before_index++;
                }
                else
                {
                    DP[i].push_back(DP[i / 2][before_index]);
                    current_index++;
                    before_index++;
                }
            }
            else if (before_index < DP[i / 2].size())
            {
                DP[i].push_back(DP[i / 2][before_index]);
                before_index++;
            }
            else if (current_index < new_values.size())
            {
                DP[i].push_back(new_values[current_index]);
                current_index++;
            }else{
                cout << "???" << endl;
            }
        }
        for(int j = 0;j+1  < DP[i].size();j++){
            if (DP[i][j].first > DP[i][j+1].first){
                cout << "!!!!" << endl;
            }
            if (DP[i][j].second > DP[i][j+1].second){
                cout << "!!!!" << endl;
            }
        }
        // cout << i << ":";
        // for(auto p:DP[i]){
        //     cout << "(" << p.first << "," << p.second << ")" ;
        // }
        // cout << endl;
    }
    ll Q;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        ll v, L;
        cin >> v >> L;
        vector<pair<ll, ll>> values;
        values.push_back({0, 0});
        while (v >= 1ll << split)
        {
            ll M = values.size();
            for(int j = 0;j < M;j++){
                if (values[j].first + W[v] <= L)
                {
                    values.push_back({values[j].first + W[v], values[j].second + V[v]});
                }
            }
            v /= 2;
        }
        ll ans = 0;
        for (auto &p : values)
        {
            ll remain = L - p.first;
            auto iter = upper_bound(DP[v].begin(),DP[v].end(),make_pair(remain,numeric_limits<ll>::max()));
            if (iter != DP[v].begin())
            {
                iter--;
                ans = max(ans, iter->second + p.second);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

int main()
{
    // ll N;
    // cin >> N;
    // for(int i = 1; i <= N;i++){
    solve();
    // }
    cout << flush;
    return 0;
}
