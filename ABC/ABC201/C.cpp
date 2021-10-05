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
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
  ll N,K;
  cin >> N >> K;
  priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, greater<pair<ll,ll>>> q;
  for(int i = 0;i < N;i++){
    ll a,b;
    cin >> a >> b;
    q.emplace(a,b);
  }
  while(!q.empty() && q.top().first <= K){
    K += q.top().second;
    q.pop();
  }
  cout << K << endl;
  return 0;
}