#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <numeric>

using namespace std;
using ll = long long;

int solve()
{
  ll n,k;
  scanf("%lld", &n);
  scanf("%lld", &k);
  string S;
  cin >> S;
  vector<ll> counts(n,0);
  if (k % 2 == 1){
    for(int i = 0;i < n;i++){
      if (S[i] == '0'){
        S[i] = '1';
      }else{
        S[i] = '0';
      }
    }
  }
  for(int i = 0;i < n;i++){
    if (S[i] == '0' && k > 0){
      counts[i]++;
      k--;
      S[i] = '1';
    }
  }
  if (k % 2 == 1){
    counts[n-1] += k;
    S[n-1] = '0';
  }else{
    counts[n-1] += k;
  }
  cout << S << "\n";
  for(int i = 0;i < n;i++){
    if (i != 0){
      cout << " ";
    }
    cout << counts[i];
  }
  cout << "\n";
  return 0;
}

int main()
{
  ll t;
  cin >> t;

  for (int i = 1; i <= t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}