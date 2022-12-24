#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <cmath>
#include <iterator>
#include <numeric>
using namespace std;
using ll = long long;

int solve()
{
  ll n,x;
  cin >> n;
  cin >> x;
  vector<ll> A(2*n);
  for(int i = 0;i < 2*n;i++){
    cin >> A[i];
  }
  sort(A.begin(),A.end());
  for(int i = 0;i < n;i++){
    if (A[i+n] - A[i] < x ){
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
  return 0;
}


int main()
{
  // 整数の入力
  ll t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}