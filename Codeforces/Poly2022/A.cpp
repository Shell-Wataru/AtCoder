#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <iterator>
#include <numeric>
using namespace std;
using ll = long long;

int solve()
{
  ll n;
  cin >> n;
  string S;
  cin >> S;
  ll total = S[0]-'0';
  for(int i = 1;i < n;i++){
    if (total > 0){
      cout << '-';
      total -= S[i]-'0';
    }else{
      cout << '+';
      total += S[i]-'0';
    }
  }
  cout << "\n";
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