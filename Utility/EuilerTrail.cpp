#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

//gが隣接リスト
//gを破壊する
vector<ll> EulerianTrail(const int s, map<ll,set<ll>> &g, const bool directed) {
        function<void (int, vector<ll> &)> dfs = [&](int u, vector<ll> &trail) {
                while (!g[u].empty()) {
                        ll v = *g[u].begin();
                        g[u].erase(v);
                        if (!directed) {
                                g[v].erase(u);
                        }
                        dfs(v, trail);
                }
                trail.push_back(u);
        };
        vector<ll> trail;
        dfs(s, trail);
        reverse(trail.begin(), trail.end());
        return trail;
}