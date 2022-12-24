#define _USE_MATH_DEFINES
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
#include <unordered_map>
#include <unordered_set>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
  ll N,Q;
  cin >> N >> Q;
  unordered_map<ll,unordered_set<ll>> G;
  for(int i = 0;i < Q;i++){
    ll t,a,b;
    cin >> t >> a >> b;
    a--;
    b--;
    if (t == 1){
      G[a].insert(b);
    }else if (t == 2){
      if (G[a].count(b)){
        G[a].erase(b);
      }
    }else{
      if (G[a].count(b) && G[b].count(a)){
        cout << "Yes\n";
      }else{
        cout << "No\n";
      }
    }
  }
  cout << flush;
  return 0;
}