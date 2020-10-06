#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <set>
#include <numeric>
#include <functional>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;
ll BASE_NUM = 1000000007;

void solve(set<pair<ll, ll>> defaults, set<pair<ll, ll>> &additions)
{
  if (defaults.size() == 0){
    return;
  }
  vector<ll> xs;
  vector<ll> ys;
  for(auto p: defaults){
    xs.emplace_back(p.first);
  }
  sort(xs.begin(),xs.end());
  ll center_x = xs[xs.size()/2];
  for(auto p: defaults){
    if (defaults.find({center_x,p.second}) == defaults.end()){
      additions.emplace(center_x,p.second);
    }
  }
  set<pair<ll,ll>> upper;
  set<pair<ll,ll>> lower;
  for(auto p: defaults){
    if (p.first > center_x){
      upper.insert(p);
    }else if (p.first < center_x ){
      lower.insert(p);
    }
  }
  solve(upper,additions);
  solve(lower,additions);
}

int main()
{
  // 整数の入力
  int N;
  cin >> N;
  set<pair<ll, ll>> defaults;
  set<pair<ll, ll>> additions;
  for (int i = 0; i < N; i++)
  {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    defaults.emplace(x, y);
  }
  solve(defaults,additions);
  cout << additions.size()<< "\n";
  for(auto p: additions){
    cout << p.first + 1 << " " << p.second + 1 << "\n";
  }
  cout << flush;
  return 0;
}