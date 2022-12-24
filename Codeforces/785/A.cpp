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
  ll total = 0;
  cin >> S;
  for(auto c:S){
    total += c-'a' + 1;
  }

  ll alice;
  ll bob;
  if (S.size() % 2 == 0){
    alice = total;
    bob = 0;
  }else{
    alice = total - min((S.front() - 'a') + 1, (S.back() - 'a') + 1);
    bob = total - alice;
  }
   if (alice > bob){
     cout << "Alice "  << alice - bob<< "\n";
   }else{
     cout << "Bob "  << bob - alice<< "\n";
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