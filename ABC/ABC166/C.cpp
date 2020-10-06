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
ll BASE_NUM = 1000000007;


int main()
{
  // 整数の入力

  ll N, M;
  cin >> N >> M;
  vector<set<ll>> G(N);
  vector<ll> H;
  for(int i = 0;i < N;i++){
    ll h;
    cin >> h;
    H.push_back(h);
  }
  for (int i = 0; i < M; i++)
  {
    ll a, b;
    cin >> a >> b;
    a--;b--;
    G[a].insert(b);
    G[b].insert(a);
  }
  ll count = 0;
  for(int i = 0;i < N;i++){
    bool highest = true;
    for(auto to:G[i]){
      if (H[i] <= H[to]){
        highest = false;
        break;
      }
    }
    if (highest){
      count++;
    }
  }
  cout << count << endl;
  return 0;
}