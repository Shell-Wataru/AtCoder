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

//https://atcoder.jp/contests/arc022/tasks/arc022_3
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
    vector<pair<ll, ll>> E = {{7, 6},
                              {3, 2},
                              {2, 4},
                              {4, 5},
                              {8, 9},
                              {1, 8},
                              {1, 6},
                              {1, 2},
                              {9, 10}};
    vector<vector<ll>>
        G(10);
    for (auto e:E)
    {
        G[e.first - 1].push_back(e.second - 1);
        G[e.second - 1].push_back(e.first - 1);
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