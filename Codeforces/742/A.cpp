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
  string S;
  ll n;
  cin >> n;
  cin >> S;
  for(auto c:S){
    if (c == 'U'){
      cout << 'D';
    }else if (c == 'L'){
      cout << 'L';
    }else if (c == 'D'){
      cout << 'U';
    }else{
      cout << 'R';
    }
  }
  cout << '\n';
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