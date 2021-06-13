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

ll next_patterns(vector<ll> &patterns, ll n,ll total){
  if (total < n){
    return patterns[total];
  }else if (total < 2*n){
    return patterns[total] - 3 * patterns[total - n];
  }else{
    return patterns[3*(n-1) - total];
  }
}

ll kireisa_patterns(ll n,ll total,ll kireisa){
  if (total < n){
    // cout << "a" << endl;
    return total - kireisa + 1;
  }else if (total < 2*n ){
    // cout << "b:" << total - kireisa + 1 << endl;
    if (kireisa >= n){
      return 0;
    }else if (total - kireisa + 1 >= n){
      return total - kireisa + 1 - 2 * (total - kireisa - n + 1);
    }else{
      return total - kireisa + 1;
    }
  }else{
    // cout << "c" << endl;
    if (kireisa >= n){
      return 0;
    }else{
      return max(2 * n - (total - kireisa) - 1,0ll);
    }
  }
}

int solve(){
  //   cout << kireisa_patterns(2,2,0) << endl;
  // cout << kireisa_patterns(2,2,1) << endl;
  // cout << kireisa_patterns(2,2,2) << endl;
  ll N,K;
  cin >> N >> K;
  // cout << K << endl;
  vector<ll> patterns(3000001, 0);
  patterns[0] = 1;
  for (int i = 1; i <= 3000000; i++)
  {
    patterns[i] = patterns[i - 1] * (i + 2) / i;
  }

  // cout << "!!!" << endl;
  ll current = 0;
  ll total = -1;
  // cout << next_patterns(patterns,2,0) << endl;
  // cout << next_patterns(patterns,2,1) << endl;
  // cout << next_patterns(patterns,2,2) << endl;
  // cout << next_patterns(patterns,2,3) << endl;
  // cout << total << endl;
  while (current + next_patterns(patterns,N,total+1) < K)
  {
    // cout << total << endl;
    // cout << current << endl;
    current += next_patterns(patterns,N,total+1);
    total += 1;
  }
  // cout << "!!!" << endl;
  total++;
  ll remain = K - current;
  // cout << "total:"<< total << endl;
  // cout << "remain:" << remain << endl;
  ll kireisa = 0;
  ll current_patterns = 0;
  // for(int i = 0;i <= total;i++){
  //   cout << kireisa_patterns(N,total,i) << endl;
  // }
  while (current_patterns + kireisa_patterns(N,total,kireisa) < remain)
  {
    current_patterns += kireisa_patterns(N,total,kireisa);
    kireisa++;
  }
  remain = remain - current_patterns;
  ll ninkido = min(total - kireisa,N-1) - remain + 1;
  ll oishisa = total - kireisa - ninkido;
  cout << kireisa + 1 << " " << oishisa + 1 << " " << ninkido + 1<< endl;
  return 0;
}
int main()
{
  ll t = 1;
  // cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }

  return 0;
}
