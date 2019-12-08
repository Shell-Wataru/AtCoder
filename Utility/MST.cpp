#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <deque>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
using ll = long long;

//mapで持っているので注意
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
    bool operator<(const edge &another) const
    {
        return cost < another.cost;
    };

    bool operator>(const edge &another) const
    {
        return cost > another.cost;
    };

};

class MST
{
    UnionFindTree uft;

public:
    priority_queue<edge,vector<edge>,greater<edge>> que;
    vector<edge> result;
    ll cost = 0;

    MST(vector<ll> &nodes, vector<edge> &edges) : uft(nodes)
    {
        for (auto e : edges)
        {
            que.push(e);
        }
        while (!que.empty())
        {
            edge e;
            e = que.top();
            if (!uft.same(e.from,e.to)){
                uft.union_tree(e.from,e.to);
                result.push_back(e);
                cost +=  e.cost;
                cout << que.top().from << que.top().to << que.top().cost << std::endl;
            }
            que.pop();
        }
        cout << cost << endl;
    }
};

int main()
{
    vector<ll> nodes{
        1, 2, 3, 4};
    vector<edge> edges{
        {1, 2, 1},
        {1, 3, 1},
        {1, 4, 0},
        {2, 3, 1},
        {2, 4, 0},
        {3, 4, 0},
    };
    MST(nodes, edges);
}
