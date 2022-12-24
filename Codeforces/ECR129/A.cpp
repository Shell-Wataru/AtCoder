#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <cmath>
#include <iterator> // std::rbegin, std::rend
#include <functional>

using namespace std;
using ll = long long;

int solve()
{
  ll n,m;
  cin >> n;
  vector<ll> A(n);
  for(int i = 0;i < n;i++){
    scanf("%lld",&A[i]);
  }
  cin >> m;
  vector<ll> B(m);
  for(int i = 0;i < m;i++){
    scanf("%lld",&B[i]);
  }
  sort(A.rbegin(),A.rend());
  sort(B.rbegin(),B.rend());
  if (A[0] >= B[0]){
    cout << "Alice\n";
  }else{
    cout << "Bob\n";
  }
  if (A[0] > B[0]){
    cout << "Alice\n";
  }else{
    cout << "Bob\n";
  }
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