#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
using namespace std;
using ll = long long;
ll BASE_NUM = 998244353;

int solve()
{
  ll n, k;
  cin >> n >> k;
  string S;
  cin >> S;
  vector<vector<ll>> swaps;
  ll total_swap = 0;
  while (true)
  {
    vector<ll> new_swaps;
    for (int i = 0; i < n - 1; i++)
    {
      // cout << S[i] << S[i + 1] << endl;
      if (S[i] == 'R' && S[i + 1] == 'L')
      {
        // cout << "hoge" << endl;
        new_swaps.push_back(i);
        total_swap++;
      }
    }

    if (new_swaps.size() > 0)
    {
      for (auto i : new_swaps)
      {
        swap(S[i], S[i + 1]);
      }
      swaps.push_back(new_swaps);
    }
    else
    {
      break;
    }
  }
  // cout << total_swap << " " << swaps.size() << endl;
  if( k < swaps.size() || k > total_swap){
    cout << -1 << endl;
  }else
  {
    ll remain_total_swap = total_swap;
    ll remain_k = k;
    for(int i = 0;i < swaps.size();i++){
      // cout << "remain_total_swap:" << remain_total_swap << "  remain_k:" <<  remain_k << endl;
      if(remain_total_swap - swaps[i].size() > remain_k - 1){
        cout << swaps[i].size();
        for(auto s:swaps[i]){
          cout << " " << s + 1;
        }
        cout << "\n";
        remain_k--;
      }else{
        cout << remain_total_swap - remain_k + 1;
        for(int j = 0;j < remain_total_swap - remain_k + 1;j++){
          cout << " " << swaps[i][j] + 1;
        }
        cout << "\n";
        for(int j = remain_total_swap - remain_k + 1;j < swaps[i].size();j++){
          cout << 1 << " " << swaps[i][j] + 1<< "\n";
          remain_k--;
        }
        remain_k--;
      }
      remain_total_swap = remain_total_swap - swaps[i].size();
    }
    cout << flush;
  }

  return 0;
}

int main()
{
  // ll t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
    solve();
  // }
  return 0;
}