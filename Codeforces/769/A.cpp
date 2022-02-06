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
  ll n;
  scanf("%lld",&n);
  string S;
  cin >> S;
  sort(S.begin(),S.end());
  if (S.front() == S.back()){
    if (n >= 2){
      cout << "NO" << endl;
    }else{
      cout << "YES" << endl;
    }
  }else{
    if (n >= 3){
      cout << "NO" << endl;
    }else{
      cout << "YES" << endl;
    }
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