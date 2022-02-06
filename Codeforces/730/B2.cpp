#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <bitset>
#include <numeric>

using namespace std;
using ll = long long;
const long long BASE_NUM = 1000000007;

vector<vector<vector<ll>>> DP(2, vector<vector<ll>>(1001, vector<ll>(1001, 0)));
int solve()
{
  ll n;
  scanf("%lld", &n);
  string s;
  cin >> s;
  ll same_count = 0;
  ll different_count = 0;
  ll is_center = 0;
  for (int i = 0; i < n / 2; i++)
  {
    if (s[i] == '0' &&  s[n-1-i] == '0'){
      same_count++;
    }else if (s[i] == '0' ||  s[n-1-i] == '0'){
      different_count++;
    }
  }
  if (n % 2 == 1 && s[n/2] == '0'){
    is_center = 1;
  }
  if (different_count == 0){
    if (DP[is_center][same_count][different_count] > 0){
      cout << "BOB\n";
    }else if (DP[is_center][same_count][different_count] == 0){
      cout << "DRAW\n";
    }else{
      cout << "ALICE\n";
    }
  }else{
      ll value = min(- DP[is_center][same_count][different_count],DP[is_center][same_count][different_count]);
      if (value > 0){
      cout << "BOB\n";
    }else if (value == 0){
      cout << "DRAW\n";
    }else{
      cout << "ALICE\n";
    }
  }

  return 0;
}

int main()
{
  ll t;
  cin >> t;
  for (int same = 0; same < 1001; same++)
  {
    for (int different = 0; different < 1001; different++)
    {
      if (same == 0)
      {
        DP[0][same][different] = different;
      }
      else if (different == 0)
      {
        DP[0][same][different] = 1 + abs(DP[0][same - 1][different + 1]);
      }
      else if (different == 1)
      {
        DP[0][same][different] = min(
          1 + abs(DP[0][same - 1][different + 1]),
          1- DP[0][same][different - 1]);
      }
      else
      {
        DP[0][same][different] = min(1 + abs(DP[0][same - 1][different + 1]), 1 + abs(DP[0][same][different - 1]));
      }
    }
  }

  for (int same = 0; same < 1001; same++)
  {
    for (int different = 0; different < 1001; different++)
    {
      if (same == 0)
      {
        if (different == 0){
          DP[1][same][different] = numeric_limits<ll>::max();
        }else if (different == 1){
          DP[1][same][different] = 1 - DP[1][same][different - 1];
        }else{
          DP[1][same][different] = 1 + abs(DP[1][same][different - 1]);
        }
      }
      else
      {
        if (different == 0)
        {
          DP[1][same][different] = 1 + abs(DP[1][same - 1][different + 1]);
        }
        else if (different == 1)
        {
          DP[1][same][different] = min(1 + abs(DP[1][same - 1][different + 1]),1 - DP[1][same][different - 1]);
        }
        else
        {
          DP[1][same][different] = min(1 + abs(DP[1][same - 1][different + 1]), 1 + abs(DP[1][same][different - 1]));
        }
      }
      if (different == 0){
        DP[1][same][different] = min(DP[1][same][different], 1 - DP[0][same][different]);
      }else{
        DP[1][same][different] = min(DP[1][same][different], 1 + abs(DP[0][same][different]));
      }

    }
  }

  // for(int i = 0;i < 10;i++){
  //   for(int j = 0;j < 10;j++){
  //     cout << DP[0][i][j] << ",";
  //   }
  //   cout << endl;
  // }
  // cout << endl;
  // for(int i = 0;i < 10;i++){
  //   for(int j = 0;j < 10;j++){
  //     cout << DP[1][i][j] << ",";
  //   }
  //   cout << endl;
  // }
  // cout << endl;
  for (int i = 1; i <= t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}