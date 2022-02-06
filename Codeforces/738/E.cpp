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

bool construct(ll n, ll k_length, string &constructed, ll first_char, vector<ll> items)
{
  vector<ll> A(n + 1, 0);
  A[0] = -1;
  ll k = -1;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < 26; j++)
    {
      ll current_k = k;
      if (items[j] > 0 && ( (i == 0 && j == first_char)  || i > 0))
      {
        while (current_k >= 0 && ('a' + j) != constructed[current_k])
          current_k = A[current_k];
        current_k++;
        if (current_k <= k_length)
        {
          items[j]--;
          A[i + 1] = current_k;
          k = current_k;
          constructed += 'a' + j;
          break;
        }
      }
    }
  }
  return constructed.size() == n;
}

ll answer(ll n, ll l, ll r,ll first_char, vector<ll> &items)
{
  if (l + 1 == r)
  {
    return r;
  }

  ll center = (l + r) / 2;
  string constructed = "";
  if (construct(n, center, constructed,first_char, items))
  {
    return answer(n, l, center,first_char, items);
  }
  else
  {
    return answer(n, center, r,first_char, items);
  }
}

int solve()
{
  string S;
  cin >> S;
  vector<ll> items(26);
  for (auto c : S)
  {
    items[c - 'a']++;
  }
  ll min_length = numeric_limits<ll>::max();
  ll min_char = -1;
  ll unique_count = 0;
  for(int i = 0;i < 26;i++){
    if (items[i] > 0){
      unique_count++;
    }
  }
  // cout << min_length << endl;
  string constructed = "";
  construct(S.size(), min_length, constructed,min_char, items);
  cout << constructed << "\n";
  return 0;
}

int main()
{
  // // 整数の入力
  ll t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}
