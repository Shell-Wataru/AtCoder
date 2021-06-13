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

using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    ll N, C;
    cin >> N >> C;
    vector<vector<pair<ll, ll>>> channel_schedules(C);
    vector<pair<ll, ll>> schedule;
    for (int i = 0; i < N; i++)
    {
        ll s, t, c;
        cin >> s >> t >> c;
        c--;
        channel_schedules[c].emplace_back(s, t);
    }
    for (int i = 0; i < C; i++)
    {
        sort(channel_schedules[i].begin(), channel_schedules[i].end());
        for (int j = 0; j < channel_schedules[i].size(); j++)
        {
            if (j == 0 || channel_schedules[i][j - 1].second != channel_schedules[i][j].first)
            {
                schedule.push_back({channel_schedules[i][j].second, channel_schedules[i][j].first});
            }
            else
            {

                schedule.back().first = channel_schedules[i][j].second;
            }
        }
    }
    // cout << schedule.size() << endl;
    sort(schedule.begin(), schedule.end());
    map<ll, ll> ends;
    for (int i = 0; i < schedule.size(); i++)
    {
        auto itr = ends.lower_bound(schedule[i].second);
        if (itr == ends.begin())
        {
            // cout << "begin" << endl;
            ends[schedule[i].first]++;
        }
        else
        {
            // cout << itr->first << endl;
            itr--;
            ends[itr->first]--;
            if (ends[itr->first] == 0)
            {
                ends.erase(itr->first);
            }
            ends[schedule[i].first]++;
        }
    }
    ll ans = 0;
    for (auto p : ends)
    {
        ans += p.second;
    }
    cout << ans << endl;
    return 0;
}