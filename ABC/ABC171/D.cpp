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


int main()
{
  // 整数の入力
  ll N;
  cin >> N;
  map<ll,ll> counts;
  for (size_t i = 0; i < N; i++)
  {
      ll a;
      cin >> a;
      counts[a]++;
  }
    ll ans = 0;
    for(auto p: counts){
        ans += p.first * p.second;
    }

    ll Q;
    cin >> Q;
    for (size_t i = 0; i < Q; i++)
    {
        ll b,c;
        cin >> b >> c;
        counts[c] += counts[b];
        ans += counts[b]* (c - b);
        counts.erase(b);
        cout << ans << endl;
    }

  return 0;
}