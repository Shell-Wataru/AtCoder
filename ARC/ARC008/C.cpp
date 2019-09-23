#include<iostream>
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

struct person {
    ll x,y,t,r;
};

const int NONE = -1;

struct S
{
    long long node, prev;
    double cost;

    S(long long n, double c, long long p) : node(n), cost(c), prev(p) {}
    bool operator>(const S &s) const
    {
        return cost > s.cost;
    }
};

class G
{
    long long n;
    vector<person> people;

  public:
    vector<double> minc;
    vector<long long> prev;

    G(long long n, vector<person> people) : n(n), people(people), minc(n, NONE), prev(n) {}

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
            for (int i = 0;i<n;i++)
            {
                if(s.node != i && minc[i] == NONE){
                    double cost = hypot(people[s.node].x -  people[i].x,people[s.node].y -  people[i].y)/min(people[s.node].t,people[i].r);
                    pq.push(S(i, s.cost + cost, s.node));
                }
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
    ll N;
    cin >> N;
    vector<person> people;
    for(int i = 0; i< N;i++){
        person p;
        cin >> p.x >> p.y >> p.t >> p.r;
        people.push_back(p);
    }
    G graph(N,people);
    graph.dijkstra(0);
    // graph.output();
    double value = 0;
    sort(graph.minc.begin(),graph.minc.end());
    for(int i = 1;i <N;i++){
        if (value < graph.minc[i] + (N - 1 - i)){
            value = graph.minc[i] + (N - 1 - i);
        }
    }

    cout << fixed <<value << endl;

    return 0;
}