#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
using namespace std;
using ll = long long;

int solve()
{
  ll n,k;
  scanf("%lld", &n);
  scanf("%lld", &k);
  string pattern = "";
  for(int i = 0; i < k;i++){
    if (i == 0){
      pattern += 'a';
    }else{
      pattern += 'a';
      pattern += 'a' + i;
      pattern += 'a' + i;
      for(int j = 1;j < i;j++){
        pattern += 'a' + j;
        pattern += 'a' + i;
      }
    }
  }
  for(int i = 0;i < n;i++){
    cout << pattern[i % pattern.size()];
  }
  cout << "\n";
  return 0;
}

int main()
{
  // int t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
    solve();
  // }
  cout << flush;
  return 0;
}