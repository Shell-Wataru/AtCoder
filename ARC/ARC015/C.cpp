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

ll BASE_NUM = 1000000007;

struct Edge
{
    ll from, to;
    double w;
};

bool bellman_ford(int n, vector<Edge> &edges, vector<double> &dists)
{
    for (int i = 0; i < n; i++)
    {
        // cout << "i" << i << endl;
        for (auto e : edges)
        {
            if (dists[e.from] != BASE_NUM && dists[e.from] * e.w < dists[e.to] )
            {
                // cout << e.from << "->" << e.to << " " << dists[e.from].value_double() << "*" << e.w.value_double() << endl;
                dists[e.to] = dists[e.from] * e.w;
                if (i == n - 1)
                {
                    return true; // n回目にも更新があるなら負の閉路が存在
                }
            }
        }
    }
    return false;
}

struct Conversion
{
    string large, small;
    ll m;
};

int main()
{
    // 整数の入力
    ll N;
    set<string> tanni;
    map<string, ll> zipped_tanni;
    map<ll, string> unzip_tanni;
    vector<Conversion> conversions;
    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        Conversion c;
        cin >> c.large >> c.m >> c.small;
        tanni.insert(c.large);
        tanni.insert(c.small);
        conversions.push_back(c);
    }

    ll count = 0;
    for (auto t : tanni)
    {
        zipped_tanni[t] = count;
        unzip_tanni[count] = t;
        count++;
    }

    ll nodes = zipped_tanni.size();
    vector<Edge> edges;
    for (auto c : conversions)
    {
        ll small_index = zipped_tanni[c.small];
        ll large_index = zipped_tanni[c.large];
        Edge e1{small_index, large_index, 1.0 * c.m};
        Edge e2{large_index, small_index, 1.0/c.m};
        edges.push_back(e1);
        edges.push_back(e2);
    }

    vector<double> dists(nodes, BASE_NUM);
    dists[0] = 1.0;
    bellman_ford(nodes, edges, dists);
    double min_v = BASE_NUM;
    double max_v = 0;
    ll min_index = 0;
    ll max_index = 0;
    for (int i = 0; i < nodes; i++)
    {
        // cout << unzip_tanni[i] << ":" << dists[i].value_double() << endl;
        if (dists[i] < min_v)
        {
            min_v = dists[i];
            min_index = i;
        }
        if (max_v < dists[i])
        {
            max_v = dists[i];
            max_index = i;
        }
    }
    cout << 1 << unzip_tanni[max_index] << "=" << (ll)(max_v / min_v + 0.5) << unzip_tanni[min_index] << endl;
    // cout << (RationalNumber(2,3)/RationalNumber(3,2)).p << endl;
    return 0;
}