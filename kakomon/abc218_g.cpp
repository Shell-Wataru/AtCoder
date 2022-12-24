#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
#include <unordered_map>
using namespace std;
using ll = long long;

pair<ll,ll> dfs(vector<ll> &A, vector<vector<ll>> &G, ll depth, ll current, ll parent, ll center)
{
    ll ret = 0;
    ll second_max = numeric_limits<ll>::min();
    if ((A[current] >= center))
    {
        ret++;
    }
    else
    {
        ret--;
        second_max = max(second_max,A[current]);
    }
    if (depth % 2 == 0)
    {
        ll next_max_value = numeric_limits<ll>::min();
        ll next_second_max = numeric_limits<ll>::min();
        for (auto to : G[current])
        {
            if (to != parent)
            {
                auto p = dfs(A, G, depth + 1, to, current, center);
                if (next_max_value < p.first){
                    next_max_value = p.first;
                    next_second_max = p.second;
                }else if (next_max_value == p.first){
                    next_second_max = max(next_second_max,p.second);
                }
            }
        }
        if (next_max_value != numeric_limits<ll>::min())
        {
            ret += next_max_value;
            second_max = max(second_max,next_second_max);
        }
    }
    else
    {
        ll next_min_value = numeric_limits<ll>::max();
        ll next_second_max = numeric_limits<ll>::max();
        for (auto to : G[current])
        {
            if (to != parent){
                auto p = dfs(A, G, depth + 1, to, current, center);
                if (next_min_value > p.first){
                    next_min_value = p.first;
                    next_second_max = p.second;
                }else if (next_min_value == p.first){
                    next_second_max = min(next_second_max,p.second);
                }
            }
        }
        if (next_min_value != numeric_limits<ll>::max())
        {
            ret += next_min_value;
            second_max = max(second_max,next_second_max);
        }
    }
    return {ret,second_max};
}
ll answer1(vector<ll> &A, vector<vector<ll>> &G, ll l, ll r)
{
    if (l + 1 == r)
    {
        return l;
    }
    ll center = (l + r) / 2;
    // cout << l << "~" << r << endl;
    auto p = dfs(A, G, 0, 0, -1, center);
    if (p.first > 0 || (p.first == 0 && (center + p.second)/2 >= center))
    {
        return answer1(A, G, center, r);
    }
    else
    {
        return answer1(A, G, l, center);
    }
}

int solve()
{
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    vector<vector<ll>> G(N);
    for (int i = 0; i < N - 1; i++)
    {
        ll u, v;
        cin >> u;
        cin >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    ll base1 = answer1(A, G, 0, 1000000001);
    // cout << base1 << endl;
    auto p = dfs(A,G,0,0,-1,base1);
    if (p.first == 0){
        cout << (base1 + p.second)/2 <<endl;
    }else{
        cout << base1 << endl;
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
    cout << flush;
    return 0;
}