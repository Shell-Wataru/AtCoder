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
using namespace std;
using ll = long long;

ll solve()
{
  ll N,K;
  scanf("%lld",&N);
  scanf("%lld",&K);
  vector<ll> A(N);
  for(int i = 0;i < N;i++){
      scanf("%lld",&A[i]);

  }
  ll length = 0;
  ll l = 0;
  ll r = 0;
  map<ll,ll> counts;
  while(r < N){
      counts[A[r]]++;
      while(counts.size() > K){
          counts[A[l]]--;
          if (counts[A[l]] == 0){
              counts.erase(A[l]);
          }
          l++;
      }
      length = max(length, r-l+1);
      r++;
  }
  cout << length << "\n";
  return 0;
}

int main()
{
  // ll N;
  // cin >> N;
  // for(int i = 1; i <= N;i++){
  solve();
  // }
  cout << flush;
  return 0;
}
