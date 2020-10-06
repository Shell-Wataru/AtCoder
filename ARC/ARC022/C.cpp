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
namespace mp = boost::multiprecision;

using namespace std;
using ll = long long;

ll BASE_NUM = 1000000007;

ll find_farthest_point(vector<vector<ll>> &G, int from, int parent, int distance, int &farthest_point, ll &farthest_distance)
{
    // cout << from << endl;
    if (distance > farthest_distance)
    {
        farthest_distance = distance;
        farthest_point = from;
    }
    for (auto to : G[from])
    {
        if (to == parent)
        {
            continue;
        }
        find_farthest_point(G, to, from, distance + 1, farthest_point, farthest_distance);
    }
    return 0;
}
int main()
{
    ll N;
    cin >> N;
    vector<vector<ll>> G(N);
    for (int i = 0; i < N - 1; i++)
    {
        ll a, d;
        cin >> a >> d;
        a--;
        d--;
        G[a].push_back(d);
        G[d].push_back(a);
    }
    int start = 0;
    ll maxDistance = 0;
    find_farthest_point(G, 0, -1, 0, start, maxDistance);
    int end = start;
    maxDistance = 0;
    find_farthest_point(G, start, -1, 0, end, maxDistance);
    cout << start + 1 << " " << end + 1 << endl;
    return 0;
}