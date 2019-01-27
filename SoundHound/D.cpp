#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <deque>
#include <cmath>
#include <map>
#include <queue>

using namespace std;
const int NONE = -1;

struct Exchange
{
    long long index, cost;
    Exchange(long long n, long long c) : index(n), cost(c) {}
    bool operator>(const Exchange &s) const
    {
        return cost > s.cost;
    }
};

struct S
{
    long long node, cost, prev;
    S(long long n, long long c, long long p) : node(n), cost(c), prev(p) {}
    bool operator>(const S &s) const
    {
        return cost > s.cost;
    }
};

class G
{
    long long n;
    vector<map<long long, long long> > cost;

  public:
    vector<long long> minc;
    vector<long long> prev;

    G(long long n, vector<map<long long, long long> > cost) : n(n), cost(cost), minc(n, NONE), prev(n) {}

    void dijkstra(long long start)
    {
        minc.assign(n, NONE);
        priority_queue<S, vector<S>, greater<S> > pq;
        pq.push(S(start, 0, NONE));
        while (!pq.empty())
        {
            S s = pq.top();
            pq.pop();
            if (minc[s.node] != NONE)
            {
                continue;
            }
            minc[s.node] = s.cost;
            prev[s.node] = s.prev;
            for (auto itr = cost[s.node].begin(); itr != cost[s.node].end(); ++itr)
            {
                pq.push(S(itr->first, s.cost + itr->second, s.node));
            }
        }
    }

    void input();
    void output()
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << ":" << minc[i] << endl;
        }
    };
};

int main()
{
    // 整数の入力
    long long n, m, s, t, i, ui, vi, ai, bi, StartYen;
    StartYen = 1e15;
    vector<map<long long, long long>> G_yen;
    vector<map<long long, long long>> G_snuke;

    cin >> n >> m >> s >> t;
    for (i = 0; i < n; i++)
    {
        map<long long, long long> yen_edges;
        map<long long, long long> snuke_edges;
        G_yen.push_back(yen_edges);
        G_snuke.push_back(snuke_edges);
    }

    for (i = 0; i < m; i++)
    {
        cin >> ui >> vi >> ai >> bi;
        G_yen[ui - 1][vi - 1] = ai;
        G_yen[vi - 1][ui - 1] = ai;
        G_snuke[vi - 1][ui - 1] = bi;
        G_snuke[ui - 1][vi - 1] = bi;
    }

    G yenMap(n, G_yen);
    G snukeMap(n, G_snuke);

    yenMap.dijkstra(s - 1);
    snukeMap.dijkstra(t - 1);
    // yenMap.output();
    // snukeMap.output();

    priority_queue<Exchange, vector<Exchange>, greater<Exchange>> total_costs;

    for (i = 0; i < n; i++)
    {
        // cout << i << ":" << yenMap.minc[i] + snukeMap.minc[i] << endl;
        total_costs.push(Exchange(i, yenMap.minc[i] + snukeMap.minc[i]));
    }

    for (i = 0; i < n; i++)
    {
        bool outputted = false;
        while (!outputted)
        {
            Exchange e = total_costs.top();
            if (e.index >= i)
            {
                outputted = true;
                cout << StartYen - e.cost << endl;
            }
            else
            {
                total_costs.pop();
            }
        }
    }

    return 0;
}