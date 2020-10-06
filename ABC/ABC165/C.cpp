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

int solve(vector<ll> &candidate, vector<vector<ll>> &Qs, ll N, ll M)
{
  if (candidate.size() == N)
  {
    ll value = 0;
    for(auto q:Qs){
      if (candidate[q[1]-1] - candidate[q[0]-1] == q[2]){
        value += q[3];
      }
    }
    return value;
  }
  else
  {
    ll max_value = 0;
    for (int i = candidate.back(); i <= M; i++)
    {
      candidate.push_back(i);
      ll value = solve(candidate,Qs,N,M);
      max_value = max(max_value,value);
      candidate.pop_back();
    }
    return max_value;
  }
}

int main()
{
  // 整数の入力

  ll N, M, Q;
  cin >> N >> M >> Q;
  vector<vector<ll>> Qs;
  for (int i = 0; i < Q; i++)
  {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    Qs.push_back({a, b, c, d});
  }
  vector<ll> candidate = {1};
  cout << solve(candidate,Qs,N,M) << endl;
  return 0;
}