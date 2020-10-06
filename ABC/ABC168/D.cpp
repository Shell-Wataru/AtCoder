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
const int NONE = -1;
template< typename T >
struct S
{
    long long node, prev;
    T cost;
    S(long long n, T c, long long p) : node(n), cost(c), prev(p) {}
    bool operator>(const S &s) const
    {
        return cost > s.cost;
    }
};

template< typename T >
class Dijkstra
{
    long long n;
    vector<map<long long, T> > G;

  public:
    vector<T> minc;
    vector<long long> prev;

    Dijkstra(vector<map<long long, T> > &G) : n(G.size()), G(G), minc(n, NONE), prev(G.size()) {}

    void solve(long long start)
    {
        minc.assign(n, NONE);
        priority_queue<S<T>, vector<S<T>>, greater<S<T>> > pq;
        pq.push(S<T>(start, 0, NONE));
        while (!pq.empty())
        {
            S<T> s = pq.top();
            pq.pop();
            if (minc[s.node] != NONE)
            {
                continue;
            }
            minc[s.node] = s.cost;
            prev[s.node] = s.prev;
            for (auto itr = G[s.node].begin(); itr != G[s.node].end(); ++itr)
            {
                pq.push(S<T>(itr->first, s.cost + itr->second, s.node));
            }
        }
    }

    void print()
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << ":" << minc[i] << endl;
        }
    };

    vector<ll> path(ll last)
    {
        vector<ll> stack;
        stack.push_back(last);
        while(prev[stack.back()] != NONE){
            stack.push_back(prev[stack.back()]);
        }
        reverse(stack.begin(),stack.end());
        return stack;
    };
};

int main()
{
  // 整数の入力
  ll N,M;
  cin >> N >> M;
  vector<map<ll,ll>> G(N);
  for(int i = 0;i< M;i++){
    ll a,b;
    scanf("%lld%lld",&a,&b);
    a--;
    b--;
    G[a][b] = 1;
    G[b][a] = 1;
  }
  Dijkstra<ll> dk(G);
  dk.solve(0);
  cout << "Yes" << endl;
  for(int i = 1;i< N;i++){
    cout << dk.prev[i] + 1 << "\n";
  }
  cout << flush;
  return 0;
}