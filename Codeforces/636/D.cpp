#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
using namespace std;
using ll = long long;
ll BASE_NUM = 998244353;


int solve()
{
  ll n,k;
  scanf("%lld%lld", &n, &k);
  vector<ll> A(n);
  vector<ll> min_count(k+1);
  vector<ll> max_count(k+1);
  map<ll,ll> counts;
  for(int i = 0;i< n;i++){
    scanf("%lld",&A[i]);
  }
  for(int i = 0;i< n/2;i++){
    min_count[min(A[i],A[n-1-i])] += 1;
    max_count[max(A[i],A[n-1-i])] += 1;
    counts[A[i]+ A[n-1-i]]++;
  }
  for(int i = 1;i<= k;i++){
    min_count[i] += min_count[i-1];
    max_count[i] += max_count[i-1];
  }

  ll min_changes = BASE_NUM;
  for(int i = 2;i<= k;i++){
    min_changes = min(1 * (min_count[i-1] - counts[i]) + (n- 2 * min_count[i-1]),min_changes);
  }
  min_changes = min(n/2 - counts[k+1],min_changes);
  for(int i = k+2;i<= 2*k;i++){
    ll ijou = n/2- max_count[i - k -1];
    min_changes = min(1 * (ijou - counts[i]) + (n- 2 * ijou),min_changes);
  }
  cout << min_changes << endl;
 return 0;
}

int main()
{
  ll t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  return 0;
}