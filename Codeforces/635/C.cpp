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

int set_childrens(ll from, ll parent, ll depth, vector<vector<ll>> &G, vector<ll> &children, vector<ll> &depths)
{
    depths[from] =depth;
    ll sum = 1;
    for (auto to : G[from])
    {
        if (to != parent)
        {
            sum += set_childrens(to, from, depth + 1, G, children, depths);
        }
    }
    children[from] = sum;
    return sum;
}

int solve()
{
    ll n, k;
    scanf("%lld%lld", &n, &k);
    vector<vector<ll>> G(n);
    vector<ll> children(n,0);
    vector<ll> depths(n,0);
    for (int i = 0; i < n - 1; i++)
    {
        ll a, b;
        scanf("%lld%lld", &a, &b);
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    set_childrens(0,-1,0,G,children,depths);
    vector<ll> points(n,0);
    for(int i = 0;i < n;i++){
        // cout << i << ": children" <<  children[i] << " depth" << depths[i] << endl;
        points[i] = children[i] - depths[i] - 1;
    }
    sort(points.begin(), points.end(), greater<ll>());
    ll ans = 0;
    for(int i = 0;i < (n-k);i++){
        // cout << points[i] << endl;
        ans += points[i];
    }
    cout << ans << endl;
    return 0;
}
int main()
{
    // 整数の入力
    // ll t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
    solve();
    // }
    return 0;
}
