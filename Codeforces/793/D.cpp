#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

vector<ll> counts;
int solve()
{
  ll n;
  scanf("%lld",&n);
  string S;
  cin >> S;
  ll odd_count = 0;

  for(auto c:S){
    if (c == '1'){
      odd_count++;
    }
  }
  if (odd_count % 2 == 1 || odd_count == 0){
    cout << "NO\n";
  }else{
    ll initial_odd = -1;
    for(int i = 0;i < n;i++){
      if (S[i] == '1'){
        initial_odd = i;
        break;
      }
    }
    stack<ll> s;
    vector<pair<ll,ll>> edges;
    for(int i = 0;i < n-1;i++){
      ll j = (i+initial_odd)%n;
      if (S[j] == '1'){
        while(s.size() >= 3){
          edges.push_back({s.top(),j});
          s.pop();
          edges.push_back({s.top(),j});
          s.pop();
        }
        s.push(j);
      }else{
        edges.push_back({s.top(),j});
        s.pop();
        while(s.size() >= 3){
          edges.push_back({s.top(),j});
          s.pop();
          edges.push_back({s.top(),j});
          s.pop();
        }
        s.push(j);
      }
    }
    ll last_j =(n-1+initial_odd)%n;
    while(s.size() > 0){
      edges.push_back({s.top(),last_j});
      s.pop();
    }
    cout << "YES\n";
    for(auto e:edges){
      cout << e.first + 1 << " " << e.second + 1 << "\n";
    }
  }

  return 0;
}

int main()
{
  ll triangles = 0;
  ll add = 0;
  // 整数の入力
  ll t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}
