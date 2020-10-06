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
  ll n;
  cin >> n;
  vector<ll> A(n);
  for (size_t i = 0; i < n; i++)
  {
    cin >> A[i];
  }
  sort(A.begin(),A.end());
  ll a = -1;
  ll b= -1;
  for(int i = 0;i < n;i++){
    if (A[i] == a + 1){
      a++;
    }else if(A[i] == b + 1){
      b++;
    }else if (A[i] == a || A[i] == b){
      continue;
    }else{
      break;
    }
  }
  cout << a + b + 2 << endl;
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
  return 0;
}