#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;
ll BASE_NUM = 998244353;

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
                // cout << que.top().from << que.top().to << que.top().cost << std::endl;
            }
            que.pop();
        }
        // cout << cost << endl;
    }
};

int main()
{
  ll n;
  vector<pair<ll,ll>> towns;
  vector<ll> costs;
  vector<ll> ks;
  vector<edge> edges;
  cin >> n;
  for(int i = 0;i<n;i++){
    pair<ll,ll> p;
    cin >> p.first >> p.second;
    towns.push_back(p);
  }
  for(int i = 0;i<n;i++){
    ll c;
    cin >> c;
    costs.push_back(c);
  }

  for(int i = 0;i<n;i++){
    ll k;
    cin >> k;
    ks.push_back(k);
  }
  for(int i = 0;i<n;i++){
    for(int j = i+1;j<n;j++){
      edges.push_back({i,j,(abs(towns[i].first - towns[j].first) + abs(towns[i].second - towns[j].second) )*(ks[i] + ks[j])});
    }
  }
  for(int i = 0;i<n;i++){
    edges.push_back({i,n,costs[i]});
  }
  vector<ll> nodes(n+1);
  for(int i = 0;i<n+1;i++){
    nodes[i] = i;
  }
  MST mst(nodes,edges);
  vector<ll> stations;
  vector<pair<ll,ll>> connections;
  for (auto e:mst.result){
    if(e.to == n){
      stations.push_back(e.from);
    }else{
      connections.push_back(make_pair(e.from,e.to));
    }
  }
  cout << mst.cost <<  "\n";
  cout << stations.size() <<  "\n";
  for(int i = 0;i< stations.size();i++){
    if (i == 0){
      cout << stations[i] + 1;
    }else{
      cout << " " << stations[i] + 1;
    }
  }
  cout << "\n";
  cout << connections.size() <<  "\n";
  for(int i = 0;i< connections.size();i++){
      cout << connections[i].first + 1<< " " << connections[i].second +  1<< "\n";
  }
  cout << flush;

  return 0;
}