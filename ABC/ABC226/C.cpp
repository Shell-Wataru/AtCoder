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
  ll N;
  cin >> N;
  ll ans = 0;
  queue<ll> q;
  set<ll> learned;
  vector<pair<ll,vector<ll>>> skills(N);
  for(int i = 0;i < N;i++){
    ll T;
    cin >> T;
    ll K;
    cin >> K;
    vector<ll> required(K);
    for(int j = 0;j < K;j++){
      cin >> required[j];
      required[j]--;
    }
    skills[i]= {T,required};
  }
  q.push(N-1);
  learned.insert(N-1);
  ans+= skills[N-1].first;
  while(!q.empty()){
    ll current = q.front();
    q.pop();
    for(auto s:skills[current].second){
      if (learned.find(s) == learned.end()){
        q.push(s);
        learned.insert(s);
        ans+= skills[s].first;
      }
    }
  }
  cout << ans << endl;
  return 0;
}