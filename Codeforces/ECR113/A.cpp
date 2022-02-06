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
  scanf("%lld",&n);
  string S;
  cin >> S;
  for(int i = 0;i < n-1;i++){
    if (S[i] == 'a' && S[i+1] == 'b'){
      cout << i+1 << " "  << i+2 << "\n";
      return 0;
    }else if(S[i] == 'b' && S[i+1] == 'a'){
      cout << i+1 << " "  << i+2 << "\n";
      return 0;
    }
  }
  cout << "-1 -1\n";
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