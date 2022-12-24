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
#include <stack>
#include <atcoder/mincostflow>
#include <unordered_map>
using namespace std;
using ll = long long;
using namespace atcoder;

int solve()
{
    ll N;
    cin >> N;
    vector<ll> A(N);
    map<ll, ll> counts;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        counts[A[i]]++;
    }
    vector<pair<ll, ll>> data;
    for (auto p : counts)
    {
        data.push_back({p.second, p.first});
    }
    if (data.size() == 1 || data.size() == 2)
    {
        sort(A.begin(), A.end());
        for (int i = 0; i < N; i++)
        {
            if (i != 0)
            {
                cout << " ";
            }
            cout << A[i];
        }
        cout << "\n";
    }
    else
    {
        sort(data.rbegin(), data.rend());
        vector<ll> ans(N);
        stack<pair<ll, ll>> s;
        ll index = 0;
        // 1つ目
        ans[index] = data[0].second;
        if (data[0].first - 1 > 0)
        {
            s.push({data[0].first - 1, data[0].second});
        }
        index++;
        ll child_index = 2;
        while (!s.empty())
        {
            if (ans[index - 1] == s.top().second && child_index < data.size())
            {
                ans[index] = data[child_index].second;
                if (data[child_index].first - 1 > 0)
                {
                    s.push({data[child_index].first - 1, data[child_index].second});
                }
                index++;
                child_index++;
            }
            else
            {
                ans[index] = s.top().second;
                index++;
                s.top().first--;
                if (s.top().first == 0)
                {
                    s.pop();
                }
            }
        }

        // 2つめ
        ans[index] = data[1].second;
        if (data[1].first - 1 > 0)
        {
            s.push({data[1].first - 1, data[1].second});
        }
        index++;
        while (!s.empty())
        {
            if (ans[index - 1] == s.top().second && child_index < data.size())
            {
                ans[index] = data[child_index].second;
                if (data[child_index].first - 1 > 0)
                {
                    s.push({data[child_index].first - 1, data[child_index].second});
                }
                index++;
                child_index++;
            }
            else
            {
                ans[index] = s.top().second;
                index++;
                s.top().first--;
                if (s.top().first == 0)
                {
                    s.pop();
                }
            }
        }
        if (child_index == data.size())
        {
            for (int i = 0; i < N; i++)
            {
                if (i != 0)
                {
                    cout << " ";
                }
                cout << ans[i];
            }
            cout << "\n";
        }
        else
        {
            sort(A.begin(), A.end());
            for (int i = 0; i < N; i++)
            {
                if (i != 0)
                {
                    cout << " ";
                }
                cout << A[i];
            }
            cout << "\n";
        }
    }

    return 0;
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    cout << flush;
    return 0;
}
