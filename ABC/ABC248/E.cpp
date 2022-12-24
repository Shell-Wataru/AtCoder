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
#include <set>
#include <climits>
using namespace std;
using ll = long long;


int solve()
{
  ll N,K;
  cin >> N >> K;
  vector<pair<ll,ll>> A(N);
  for(int i = 0;i < N;i++){
    cin >> A[i].first >> A[i].second;
  }
  if (K == 1){
    cout << "Infinity" << endl;
    return 0;
  }
  set<vector<ll>> cleared;
  for(int i = 0;i < N;i++){
    for(int j = i + 1;j < N;j++){
      ll a = A[i].second - A[j].second;
      ll b = -(A[i].first - A[j].first);
      ll c =  - (A[i].second - A[j].second) * A[i].first +  (A[i].first - A[j].first) * A[i].second;
      ll g = gcd(a,gcd(b,c));
      if (a < 0){
        g *= -1;
      }else if(a == 0 && b < 0){
        g *= -1;
      }else if (a == 0 && b == 0 && c < 0){
        g *= -1;
      }
      a /= g;
      b /= g;
      c /= g;

      ll count = 0;
      for(int k = 0;k < N;k++){
        if (a * A[k].first + b * A[k].second + c  == 0) {
          count++;
        }
      }
      if (count >= K){
        cleared.insert({a,b,c});
      }
    }
  }
  cout << cleared.size() << endl;
  return 0;
}

int main()
{
  // ll N;
  // cin >> N;
  // for(int i = 0;i < N;i++){
  solve();
  // }
  cout << flush;
  return 0;
}
