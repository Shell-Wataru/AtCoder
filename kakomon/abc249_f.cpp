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
using namespace std;
using ll = long long;

int main()
{
    ll N, K;
    cin >> N >> K;
    vector<pair<ll, ll>> operations;
    //   operations.push_back({1,0});
    for (int i = 0; i < N; i++)
    {
        ll t, y;
        cin >> t >> y;
        operations.push_back({t, y});
    }
    priority_queue<ll, vector<ll>, greater<ll>> using_q;
    priority_queue<ll> not_using_q;
    ll not_use = 0;
    ll total = 0;
    ll ans = numeric_limits<ll>::min();
    for (int i = ((ll)operations.size()) - 1; i >= 0; i--)
    {
        ll t = operations[i].first;
        ll y = operations[i].second;
        if (t == 1)
        {
            while (!not_using_q.empty() && (not_using_q.size() + not_use > K || not_using_q.top() >= 0))
            {
                using_q.push(not_using_q.top());
                total += not_using_q.top();
                not_using_q.pop();
            }
            while (!using_q.empty() && using_q.top() < 0 && not_using_q.size() + not_use < K)
            {
                not_using_q.push(using_q.top());
                total -= using_q.top();
                using_q.pop();
            }
            if (not_using_q.size() + not_use <= K)
            {
                ans = max(ans, y + total);
            }
            not_use++;
        }
        else
        {
            not_using_q.push(y);
            // total += y;
        }
    }
    while (!not_using_q.empty() && (not_using_q.size() + not_use > K || not_using_q.top() >= 0))
    {
        using_q.push(not_using_q.top());
        total += not_using_q.top();
        not_using_q.pop();
    }
    while (!using_q.empty() && using_q.top() < 0 && not_using_q.size() + not_use < K)
    {
        not_using_q.push(using_q.top());
        total -= using_q.top();
        using_q.pop();
    }
    if (not_using_q.size() + not_use <= K)
    {
        ans = max(ans, total);
    }
    cout << ans << endl;
    return 0;
}
