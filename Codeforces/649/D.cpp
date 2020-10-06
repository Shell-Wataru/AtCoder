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
int BASE_NUM = 998244353;

void dfs(int k,int parent,int current,int depth,vector<int> &cycle,vector<vector<int>> &G,vector<int> &visit_depth){
  // cout << current << endl;
  if (visit_depth[current] != -1){
    // cout << current << parent<< endl;
    // cout << depth << "-"<< visit_depth[current] << endl;
    if (depth - visit_depth[current] <= k){
      cycle.push_back(current);
    }
    return;
  }

  visit_depth[current] = depth;
  for(auto to:G[current]){
    if (to != parent && cycle.size() == 0){
      dfs(k,current,to,depth+1,cycle,G,visit_depth);
    }
  }
  // cout << "C" << endl;
  if (cycle.size() == 1 || (cycle.size() > 1 && cycle.back() != cycle.front())){
    cycle.push_back(current);
  }
  return;
}

void write_dfs(int parent,int current,int depth, int  &must_write,vector<vector<int>> &G){
  if (must_write == 0){
    return;
  }
  if (depth % 2 == 0){
    if (current != 0){
      cout << " ";
    }
    cout << current + 1;
    must_write--;
  }
  for(auto to:G[current]){
    if (to != parent){
      write_dfs(current,to,depth+1,must_write,G);
    }
  }
}
int solve()
{
  int n, m , k;
  cin >> n >> m >> k;
  vector<vector<int>> G(n);
  for (size_t i = 0; i < m; i++)
  {
    int a,b;
    scanf("%d",&a);
    scanf("%d",&b);
    a--;b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<int> cycle;
  vector<int> visit_depth(n,-1);
  dfs(k,-1,0,0,cycle,G,visit_depth);
  if (cycle.size() > 0){
    cout << 2 << endl;
    cout << cycle.size() - 1 << endl;
    for (size_t i = 0; i < cycle.size() -1; i++)
    {
      if (i!=0){
        cout << " ";
      }
      cout << cycle[i] + 1;
    }
    cout << endl;
  }else{
    cout << 1 << endl;
    int must_write = (k+1)/2;
    write_dfs(-1,0,0,must_write,G);
    cout << endl;
  }
  // cout << "A" << endl;
  return 0;
}

int main()
{
  // int t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
    solve();
  // }
  // cout << flush;
  return 0;
}