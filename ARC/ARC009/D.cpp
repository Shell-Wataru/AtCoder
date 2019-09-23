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
namespace mp = boost::multiprecision;

class UnionFindTree
{
    map<ll, ll> union_tree_data;

public:
    UnionFindTree() {}

    UnionFindTree(vector<ll> verticals)
    {
        for (auto v : verticals)
        {
            union_tree_data[v] = v;
        }
    }

    void add_vertical(ll v)
    {
        union_tree_data[v] = v;
    }

    void reset()
    {
        for (auto &pair : union_tree_data)
        {
            pair.second = pair.first;
        }
    }
    long long find(long long N)
    {
        if (union_tree_data[N] == N)
        {
            return N;
        }
        else
        {
            return union_tree_data[N] = find(union_tree_data[N]);
        }
    }

    bool same(long long x, long long y)
    {
        return find(x) == find(y);
    }

    void union_tree(long long x, long long y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        union_tree_data[x] = y;
    }
};

class edge
{
public:
    ll from, to, cost;
};

class MST
{
public:
    vector<edge> edges;
    vector<ll> verticals;
    map<set<ll>, ll> using_edge_cached_data;
    map<set<ll>, ll> ban_edge_cached_data;
    vector<ll> kth_costs;

    ll current_cost, next_cost, next_remove_edge_cache;
    UnionFindTree uft;

    void add_vertical(ll v)
    {
        verticals.push_back(v);
        uft.add_vertical(v);
    }

    bool contains_vertical(ll v)
    {
        return binary_search(verticals.begin(), verticals.end(), v);
    }

    pair<ll, set<ll>> solve(set<ll> &ban_edges)
    {
        ll union_count = 0;
        ll cost = 0;
        set<ll> using_edges;
        uft.reset();

        for (int i = 0; i < edges.size(); i++)
        {
            if (ban_edges.find(i) != ban_edges.end())
            {
                continue;
            }
            edge &e = edges[i];
            if (!uft.same(e.from, e.to))
            {
                uft.union_tree(e.from, e.to);
                cost += e.cost;
                union_count++;
                using_edges.insert(i);
                if (union_count == verticals.size() - 1)
                {
                    break;
                }
            }
        }

        if (union_count != verticals.size() - 1)
        {
            return make_pair(-1, using_edges);
        }
        else
        {
            return make_pair(cost, using_edges);
        }
    }

    ll solve_kth()
    {
        sort(edges.begin(), edges.end(), [](edge &x, edge &y) -> ll {
            return x.cost > y.cost;
        });
        queue<pair<set<ll>, set<ll>>> q;
        set<ll> b;
        pair<ll, set<ll>> p = solve(b);
        ll cost = p.first;
        set<ll> &u = p.second;
        ban_edge_cached_data[b] = cost;
        using_edge_cached_data[u] = cost;
        q.push(make_pair(b, u));
        while (!q.empty())
        {
            set<ll> &current_tree = q.front().second;
            for (auto e : current_tree)
            {
                set<ll> ban_edges = q.front().first;
                ban_edges.insert(e);

                if (ban_edge_cached_data.find(ban_edges) != ban_edge_cached_data.end())
                {
                    continue;
                }
                pair<ll, set<ll>> &&p = solve(ban_edges);
                ll cost = p.first;
                set<ll> &u = p.second;
                ban_edge_cached_data[ban_edges] = cost;

                if (cost != -1 && using_edge_cached_data.find(u) == using_edge_cached_data.end())
                {
                    using_edge_cached_data[u] = cost;
                    q.push(make_pair(ban_edges, u));
                }
            }
            q.pop();
        }

        for (auto &a : using_edge_cached_data)
        {
            kth_costs.push_back(a.second);
            sort(kth_costs.begin(), kth_costs.end(), [](ll x, ll y) -> ll {
                return x > y;
            });
        }
        return 0;
    }

    void print_all()
    {
        for (auto a : using_edge_cached_data)
        {
            for (auto e : a.first)
            {
                cout << e << ",";
            }
            cout << ":" << a.second << endl;
        }
    }
};

int main()
{
    // 整数の入力
    ll A, T, k, M;
    vector<MST> cities;
    ll total = 0;
    cin >> A >> T >> k;
    for (int i = 0; i < A; i++)
    {
        ll N;
        cin >> N;
        MST c;
        for (int j = 0; j < N; j++)
        {
            ll town;
            cin >> town;
            c.add_vertical(town);
        }
        cities.push_back(c);
    }

    for (auto &c : cities)
    {
        sort(c.verticals.begin(),c.verticals.end());
    }

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        edge e;
        cin >> e.from >> e.to >> e.cost;
        total += e.cost;
        for (auto &c : cities)
        {
            if (c.contains_vertical(e.from) && c.contains_vertical(e.to))
            {
                c.edges.push_back(e);
                break;
            }
        }
    }

    for (auto &c : cities)
    {
        c.solve_kth();
    }


    vector<ll> costs;
    costs.push_back(0);
    for (auto &city : cities)
    {
        vector<ll> new_costs;
        for (auto &c : costs)
        {
            for (auto city_cost : city.kth_costs)
            {
                new_costs.push_back(c + city_cost);
            }
        }
        sort(new_costs.begin(), new_costs.end(), greater<ll>());
        costs.clear();
        for(int i =0;i<k && i< new_costs.size();i++){
            costs.push_back(new_costs[i]);
        }
    }

    // for(auto a :costs){
    //     cout << a << endl;
    // }
    // cout << costs.size() << endl;
    if(k <= costs.size()){
        // cout << costs[k - 1] << endl;
        cout << total - costs[k - 1] << endl;
    }else{
        cout << -1 << endl;
    }

    return 0;
}
