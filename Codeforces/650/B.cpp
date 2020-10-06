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

using namespace std;
using ll = long long;
const ll BASE_NUM = 1000000007;

int solve()
{
  ll n;
  cin >> n;
  vector<ll> A(n);
  ll odd_bads = 0;
  ll even_bads = 0;
  for (size_t i = 0; i < n; i++)
  {
    cin >> A[i];
    if (i % 2 != A[i] %2){
      if (i % 2 == 0){
        even_bads++;
      }else{
        odd_bads++;
      }
    }
  }
  if (even_bads == odd_bads){
    cout << even_bads << endl;
  }else{
    cout << -1 << endl;
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
