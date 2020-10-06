#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <numeric>

using namespace std;
using ll = long long;
const ll BASE_NUM = 1000000007;

// 3D cross product of OA and OB vectors, (i.e z-component of their "2D" cross product, but remember that it is not defined in "2D").
// Returns a positive value, if OAB makes a counter-clockwise turn,
// negative for clockwise turn, and zero if the points are collinear.
ll cross(pair<ll, ll> &O, pair<ll, ll> &A, pair<ll, ll> &B)
{
    return (A.first - O.first) * (B.second - O.second) - (A.second - O.second) * (B.first - O.first);
}

// Returns a list of points on the convex hull in counter-clockwise order.
// Note: the last point in the returned list is the same as the first one.
vector<pair<ll, ll>> convex_hull(vector<pair<ll, ll>> P)
{
    size_t n = P.size(), k = 0;
    if (n <= 3)
        return P;
    vector<pair<ll, ll>> H(2 * n);

    // Sort points lexicographically
    sort(P.begin(), P.end());

    // Build lower hull
    for (size_t i = 0; i < n; ++i)
    {
        while (k >= 2 && cross(H[k - 2], H[k - 1], P[i]) <= 0)
            k--;
        H[k++] = P[i];
    }

    // Build upper hull
    for (size_t i = n - 1, t = k + 1; i > 0; --i)
    {
        while (k >= t && cross(H[k - 2], H[k - 1], P[i - 1]) <= 0)
            k--;
        H[k++] = P[i - 1];
    }

    H.resize(k - 1);
    return H;
}

int solve()
{
    ll n,m;
    scanf("%lld", &n);
    scanf("%lld", &m);
    vector<pair<ll,ll>> robbers(n);
    vector<pair<ll,ll>> searchlights(m);
    for (size_t i = 0; i < n; i++)
    {
        scanf("%lld",&robbers[i].first);
        scanf("%lld",&robbers[i].second);
    }
    for (size_t i = 0; i < m; i++)
    {
        scanf("%lld",&searchlights[i].first);
        scanf("%lld",&searchlights[i].second);
    }

    vector<pair<ll,ll>> must_moves;
    for(auto &r:robbers){
        for(auto &s:searchlights){
            must_moves.push_back({s.first - r.first,s.second - r.second});
        }

    }
    sort(must_moves.begin(),must_moves.end());
    // for(auto m: must_moves){
    //     cout << m.first << " " << m.second << endl;
    // }
    vector<ll> max_ups(must_moves.size()+1,-1);
    for(int i = must_moves.size()-1;i >= 0;i--){
        max_ups[i] = max(max_ups[i+1],must_moves[i].second);
    }
    // for(int i = 0;i < max_ups.size();i++){
    //     cout << max_ups[i] << endl;
    // }
    ll min_move = max_ups[0] + 1;
    for(int i = 0;i < must_moves.size();i++){
        // cout << must_moves[i].first << " " << max_ups[i+1] << endl;
        // cout << max(must_moves[i].first,-1ll) + max(max_ups[i+1],-1ll) + 2 << endl;
        min_move = min(min_move,max(must_moves[i].first,-1ll) + max(max_ups[i+1],-1ll) + 2);
    }
    cout << min_move << endl;

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
    // cout << flush;
    return 0;
}
