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

int dfs1(int from, int parent, vector<vector<ll>> &G, vector<ll> &sizes)
{
    ll size = 1;
    for (auto &to : G[from])
    {
        if (to != parent)
        {
            size += dfs1(to, from, G, sizes);
        }
    }
    sizes[from] = size;
    return size;
}

int dfs2(int from, int parent, int d_parent, vector<vector<ll>> &G, vector<ll> &sizes, vector<ll> &max_sizes)
{
    ll max_size = d_parent;
    for (auto &to : G[from])
    {
        if (to != parent)
        {
            max_size = max(max_size, sizes[to]);
        }
    }
    max_sizes[from] = max_size;
    for (auto &to : G[from])
    {
        if (to != parent)
        {
            dfs2(to, from, G.size() - sizes[to], G, sizes, max_sizes);
        }
    }
    return max_size;
}
int main()
{
    ll N;
    cin >> N;
    vector<vector<ll>> G(N);
    for (int i = 1; i <= N - 1; i++)
    {
        ll p;
        cin >> p;
        G[i].push_back(p);
        G[p].push_back(i);
    }
    vector<ll> sizes(N);
    vector<ll> max_sizes(N);
    dfs1(0,-1,G,sizes);
    dfs2(0,-1,0,G,sizes,max_sizes);
    // cout << "==" << endl;
    // for(auto s:sizes){
    //     cout << s << endl;
    // }
    // cout << "==" << endl;
    for(auto s:max_sizes){
        cout << s << endl;
    }
    return 0;
}