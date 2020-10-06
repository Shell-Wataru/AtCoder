#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
using namespace std;
using ll = long long;

string solve()
{
    ll C, D;
    cin >> C >> D;
    vector<pair<ll, ll>> Order;
    vector<ll> Latency(D,1000);
    vector<ll> ArrivedTime(C, 1e9);
    ArrivedTime[0] = 0;
    vector<pair<ll, ll>> Time;
    vector<vector<pair<ll, ll>>> G(C);
    for (int i = 0; i < C - 1; i++)
    {
        ll x;
        cin >> x;
        if (x > 0)
        {
            Time.push_back({x, i + 1});
        }
        else
        {
            Order.push_back({-x, i + 1});
        }
    }
    sort(Order.begin(), Order.end());
    sort(Time.begin(), Time.end());
    for (int i = 0; i < D; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back({b, i});
        G[b].push_back({a, i});
    }
    ll order = 0;
    ll order_index = 0;
    ll order_index_time = 0;
    ll time_index = 0;
    ll decided = 1;
    while (order_index < Order.size() || time_index < Time.size())
    {
        // cout << order_index << " " << time_index << endl;
        if (order_index < Order.size() && Order[order_index].first == order)
        {
            // cout << "a" << endl;
            ll to = Order[order_index].second;
            ll min_time = 1e9;
            ll min_time_index = -1;
            ll min_time_edge_index = -1;
            for (auto &from : G[to])
            {
                if (ArrivedTime[from.first] < min_time)
                {
                    min_time = ArrivedTime[from.first];
                    min_time_index = from.first;
                    min_time_edge_index = from.second;
                }
            }
            ArrivedTime[to] = order_index_time;
            Latency[min_time_edge_index] = order_index_time - min_time;
            order_index++;
            decided++;
        }
        else if (order_index < Order.size() && Order[order_index].first == decided)
        {
            // cout << "b" << endl;
            ll to = Order[order_index].second;
            ll min_time = 1e9;
            ll min_time_index = -1;
            ll min_time_edge_index = -1;
            for (auto &from : G[to])
            {
                if (ArrivedTime[from.first] < min_time)
                {
                    min_time = ArrivedTime[from.first];
                    min_time_index = from.first;
                    min_time_edge_index = from.second;
                }
            }
            ArrivedTime[to] = order_index_time + 1;
            Latency[min_time_edge_index] = order_index_time + 1 - min_time;
            order_index_time = order_index_time + 1;
            order = decided;
            decided++;
            order_index = decided - 1;
        }
        else
        {
            // cout << "c" << endl;
            ll to = Time[time_index].second;
            ll min_time = 1e9;
            ll min_time_index = -1;
            ll min_time_edge_index = -1;
            for (auto &from : G[to])
            {
                if (ArrivedTime[from.first] < min_time)
                {
                    min_time = ArrivedTime[from.first];
                    min_time_index = from.first;
                    min_time_edge_index = from.second;
                }
            }
            ArrivedTime[to] = Time[time_index].first;
            Latency[min_time_edge_index] = ArrivedTime[to] - min_time;
            decided++;
            time_index++;
            if (order_index_time == ArrivedTime[to])
            {
            }
            else
            {
                order_index_time = ArrivedTime[to];
                order = decided - 1;
            }
        }
    }
    string ans = "";
    for (int i = 0; i < D; i++)
    {
        if (i != 0)
        {
            ans += " ";
        }
        ans += to_string(Latency[i]);
    }
    return ans;
}
int main()
{
    // 整数の入力
    ll T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        string ans = solve();
        cout << "Case #" << i << ": " << ans << endl;
    }

    return 0;
}