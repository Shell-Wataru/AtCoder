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
  vector<ll> A(10,1);
  ll total = 1;
  ll index = 0;
  while(total < n){
    total /= A[index];
    A[index]++;
    total *= A[index];
    index = (index + 1) % 10;
  }
  string S= "codeforces";
  for(int i = 0;i < 10;i++){
    for (size_t j = 0; j < A[i]; j++)
    {
      cout << S[i];
    }
  }
  cout << endl;
  return 0;
}
int main()
{
  // ll t;
  // cin >> t;
  // for (int i = 1; i <= t; i++)
  // {
    solve();
  // }
  return 0;
}
