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

string repeats(string S, ll k)
{
  string value = "";
  while (value.size() < k)
  {
    value += S;
  }
  return value.substr(0, k);
}
int solve()
{
  int n, k;
  scanf("%d", &n);
  scanf("%d", &k);
  string S;
  cin >> S;
  vector<ll> A(S.size());
  int i = 1, j = 0;
  while (i < S.size())
  {
    while (i + j < S.size() && S[j] == S[i + j])
      ++j;
    A[i] = j;
    if (j == 0)
    {
      ++i;
      continue;
    }
    int k = 1;
    while (i + k < S.size() && k + A[k] < j)
      A[i + k] = A[k], ++k;
    i += k;
    j -= k;
  }
  ll ans_index = 0;
  for (int i = 1; i < n;)
  {
    ll diff = min(A[i], ans_index + 1);
    // cout << i << endl;
    // cout << i+diff << endl;
    // cout << diff << ":" << ans_index + 1 << endl;
    if (diff == ans_index + 1){
      ans_index = i + diff - 1;
      i = ans_index + 1;
    }else if (i+diff == n){
      // cout << "!!!" << endl;
      // string ans = repeats(S.substr(0, ans_index + 1), k);
      // ans = min(ans,repeats(S,k));
      // cout << ans << "\n";
      i = i+diff;
      // return 0;
    }else if (S[i + diff] < S[diff])
    {
      ans_index = i + diff;
      i = ans_index + 1;
    }
    else
    {
      break;
    }
  }
  cout << repeats(S.substr(0, ans_index + 1), k) << "\n";
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