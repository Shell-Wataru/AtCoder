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
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;

int main()
{
    ll N, M;
    cin >> N >> M;
    vector<vector<vector<ll>>> G(N);
    for (size_t i = 0; i < M; i++)
    {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        G[a].push_back({b, c, d});
        G[b].push_back({a, c, d});
    }
    vector<ll> T(N, numeric_limits<ll>::max());
    priority_queue<pair<ll, ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
    q.push({0, 0});
    while (!q.empty())
    {
        ll t = q.top().first;
        ll current = q.top().second;
        q.pop();
        if (t >= T[current])
        {
            continue;
        }
        T[current] = t;
        for (auto e : G[current])
        {
            ll to = e[0];
            ll c = e[1];
            ll d = e[2];
            ll best_t = max((ll)sqrt(d) - 1,t);
            ll min_t = best_t+c+d/(best_t+1);
            min_t = min(min_t,best_t+1+c+d/(best_t+2));
            q.push({min_t,to});
        }
    }
    if (T[N-1] == numeric_limits<ll>::max()){
        cout << -1 << endl;
    }else{
        cout << T[N-1] << endl;
    }
    return 0;
}