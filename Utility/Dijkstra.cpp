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
