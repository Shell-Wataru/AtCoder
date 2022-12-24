#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <numeric>

using namespace std;
using ll = long long;

int solve()
{
  ll n,m;
  scanf("%lld",&n);
  scanf("%lld",&m);
  string S;
  cin >> S;
  vector<ll> answers(n*m,0);
  vector<bool> columns(m,false);
  vector<ll> filled_rows(m,0);
  ll filled_columns = 0;
  for(int i = 0;i < n*m;i++){
    if (S[i] == '1'){
      if (!columns[i % m]){
        filled_columns++;
        columns[i%m] = true;
      }
    }
    answers[i] += filled_columns;
  }
  ll one_count = 0;
  for(int i = 0;i < n*m;i++){
    if (i >= m){
      if (S[i-m] == '1'){
        one_count--;
      }
    }
    if (S[i] == '1'){
      one_count++;
    }
    if (one_count > 0){
      filled_rows[i%m]++;
    }
    answers[i] += filled_rows[i%m];
  }
  for(int i = 0;i < n*m;i++){
    cout << answers[i] << " ";
  }
  cout << "\n";
  return 0;
}

int main()
{
  ll t;
  cin >> t;

  for (int i = 1; i <= t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}