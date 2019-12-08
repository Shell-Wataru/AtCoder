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

void remove_nodes(ll n, ll current_node, set<ll> &nodes, set<pair<ll, ll>> &edges, set<ll> &target_nodes)
{
  target_nodes.insert(current_node);
  for (int i = 0; i < n; i++)
  {
    if (edges.find(make_pair(current_node, i)) == edges.end() &&
        target_nodes.find(i) == target_nodes.end() &&
        nodes.find(i) != nodes.end())
    {
      remove_nodes(n,i,nodes,edges,target_nodes);
    }
  }
}

int main()
{
  ll n, m;
  cin >> n >> m;
  set<ll> nodes;
  set<pair<ll, ll>> edges;
  for (int i = 0; i < m; i++)
  {
    ll from,to;
    cin >> from >> to;
    from--;
    to--;
    edges.insert(make_pair(from,to));
    edges.insert(make_pair(to,from));
  }
  for (ll i = 0; i < n; i++)
  {
    nodes.insert(i);
  }

  ll total = 0;
  while (nodes.size() > 0)
  {
    total++;
    cout << "==========" << endl;
    cout << *nodes.begin() << endl;
    set<ll> target_nodes;
    remove_nodes(n, *nodes.begin(), nodes, edges, target_nodes);
    cout << target_nodes.size() << endl;
    cout << nodes.size() << endl;
    for(ll node:target_nodes){
      cout << node;
      nodes.erase(node);
    }
    cout << endl;
    cout << nodes.size() << endl;
  }
  cout << total - 1 << endl;
  return 0;
}