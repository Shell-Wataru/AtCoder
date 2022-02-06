#include <iostream>
#include <cstdio>
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
const long long BASE_NUM = 1000000007;

string repeats(string S,ll k){
    string value = "";
    while(value.size() < k){
        value += S;
    }
    return value.substr(0,k);
}
int solve()
{
  int n,k;
  scanf("%d", &n);
  scanf("%d", &k);
  string S;
  cin >> S;
  string ans = repeats(S.substr(0,1),k);
  for(int i = 2;i <= n;i++){
      string new_one = repeats(S.substr(0,i),k);
      if (new_one < ans){
          ans = new_one;
      }
  }
  cout << ans << "\n";
  return 0;
}

int main()
{
  // // 整数の入力
  ll t = 1;
//   cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}
