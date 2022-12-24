#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

int solve()
{
  ll l,r;
  scanf("%lld", &l);
  scanf("%lld", &r);
  vector<ll> c(r-l+1);
  vector<ll> answer_counts(17);
  vector<ll> same_biggest(17);
  vector<ll> input_counts(17);
  for (size_t i = 0; i < r-l+1; i++)
  {
    scanf("%lld",&c[i]);
  }
  if (r == 0){
    cout << c[0] << "\n";
    return 0;
  }
  ll biggest_index = -1;
  for(int i = 16;i>= 0;i--){
    if (r & 1ll<<i){
      biggest_index = i;
      break;
    }
  }
  for (size_t i = 0; i < r-l+1; i++)
  {
    for(int j = 0;j < 17;j++){
      if (c[i] & 1ll<<j){
        input_counts[j]++;
      }
      if (c[i] & 1ll<<j && c[i] & 1ll<<biggest_index){
        input_counts[j]++;
      }
    }
  }

  for (int i = l; i <= r; i++)
  {
    for(int j = 0;j < 17;j++){
      if (i & 1ll<<j){
        answer_counts[j]++;
      }
    }
  }
  ll x = 0;
  for(int j = 0;j < 17;j++){
    if (input_counts[j] != answer_counts[j]){
      x |= 1ll<<j;
    }else if ( input_counts[j]*2 == r-l+1){
      cout << "!" << j << endl;
      // x |= 1ll<<j;
    }else{

    }
  }
  for(int i = 0;i < r-l+1;i++){
    cout << (c[i]^x) << " ";
  }
  cout << "\n";
  cout << x << "\n";
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
