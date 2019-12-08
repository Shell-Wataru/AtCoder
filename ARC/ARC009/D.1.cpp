d.1#include <iostream>
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
    vector<pair<ll, ll>> kth_costs;

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

    ll solve_kth()
    {
        map<ll, ll> cost_counts;
        ll n = edges.size();
        ll r = verticals.size() - 1;
        vector<bool> v(n);
        fill(v.end() - r, v.end(), true);
        do
        {
            ll cost = 0;
            bool is_spine_tree = true;
            uft.reset();
            for (int i = 0; i < n; ++i)
            {
                if (v[i])
                {
                    edge &e = edges[i];
                    if (!uft.same(e.from, e.to))
                    {
                        uft.union_tree(e.from, e.to);
                        cost += e.cost;
                    }
                    else
                    {
                        is_spine_tree = false;
                        break;
                    }
                }
            }
            if (is_spine_tree)
            {
                cost_counts[cost]++;
            }
        } while (std::next_permutation(v.begin(), v.end()));

        for (auto &p : cost_counts)
        {
            kth_costs.push_back(p);
        }
        sort(kth_costs.begin(), kth_costs.end(), greater<pair<ll, ll>>());
        return 0;
    }
};

struct value
{
    ll i, j, cost, count;
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
        sort(c.verticals.begin(), c.verticals.end());
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

    vector<pair<ll, ll>> costs_count;
    auto compare = [](value a, value b) {
        return a.cost < b.cost;
    };
    costs_count.push_back(make_pair(0, 1));
    for (auto &city : cities)
    {
        ll total_count = 0;
        map<ll, ll> new_costs;
        value first_v = {0, 0, costs_count[0].first + city.kth_costs[0].first, min(costs_count[0].second * city.kth_costs[0].second, k)};
        priority_queue<value,
                       std::vector<value>,
                       decltype(compare)>
            que(compare);
        que.push(first_v);
        set<pair<ll, ll>> pushed;
        pushed.insert(make_pair(0, 0));
        while (!que.empty() && total_count < k)
        {
            value v = que.top();
            total_count += v.count;
            que.pop();
            pair<ll, ll> p1 = make_pair(v.i + 1, v.j);
            if (v.i + 1 < costs_count.size() && pushed.find(p1) == pushed.end())
            {
                pushed.insert(p1);
                que.push({v.i + 1, v.j, costs_count[v.i + 1].first + city.kth_costs[v.j].first, min(costs_count[v.i + 1].second * city.kth_costs[v.j].second, k)});
            }

            pair<ll, ll> p2 = make_pair(v.i, v.j + 1);
            if (v.j + 1 < city.kth_costs.size() && pushed.find(p2) == pushed.end())
            {
                pushed.insert(p2);
                que.push({v.i, v.j + 1, costs_count[v.i].first + city.kth_costs[v.j + 1].first, min(costs_count[v.i].second * city.kth_costs[v.j + 1].second, k)});
            }
            new_costs[v.cost] += v.count;
        }
        costs_count.clear();
        for (auto &a : new_costs)
        {
            costs_count.push_back(a);
        }
        sort(costs_count.begin(), costs_count.end(), greater<pair<ll, ll>>());
    }

    // cout << "size" << costs.size() << endl;
    // for(auto a :costs){
    //     cout << a << endl;
    // }

    ll total_count = 0;
    for (auto a : costs_count)
    {
        total_count += a.second;
        if (total_count >= k)
        {
            cout << total - a.first << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}
