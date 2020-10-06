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
  vector<ll> A(n),B(n);
  ll min_a = BASE_NUM;
  ll min_b = BASE_NUM;
  for(int i = 0;i < n;i++){
    cin >> A[i];
    min_a = min(min_a,A[i]);
  }
  for(int i = 0;i < n;i++){
    cin >> B[i];
    min_b = min(min_b,B[i]);
  }
  ll ope = 0;
  for(int i = 0;i < n;i++){
    ope += max(A[i] - min_a, B[i] - min_b);
  }
  cout << ope << endl;
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
