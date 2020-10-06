#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <bitset>
#include <numeric>

using namespace std;
using ll = long long;
const ll BASE_NUM = 1000000007;

int solve()
{
  ll n,k;
  cin >> n >> k;
  vector<ll> A(n);
  for (size_t i = 0; i < n; i++)
  {
    cin >> A[i];
  }
  ll unique_numbers = 0;
  ll current = -1;
  for(int i = 0;i < n;i++){
    if (A[i] != current){
      unique_numbers++;
      current = A[i];
    }
  }
  if (unique_numbers <= k){
    cout << 1 << endl;
  }else if (k == 1){
    cout << -1 << endl;
  }else{

  }
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
  return 0;
}
