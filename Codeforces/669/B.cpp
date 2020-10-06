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
  ll n;
  cin >> n;
  vector<ll> A(n);
  for(int i = 0;i < n;i++){
    cin >> A[i];
  }
  ll c = 0;
  for(int i = 0;i < n;i++){
    sort(A.begin()+i,A.end(),[c](ll l,ll r){
      return gcd(c,l) > gcd(c,r);
    });
    c = gcd(c,A[i]);
  }
  for(int i = 0;i < n;i++){
    if (i != 0){
      cout << " ";
    }
    cout << A[i];
  }
  cout << endl;
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
