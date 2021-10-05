#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>

using namespace std;
using ll = long long;

int main()
{
  // 整数の入力
  ll N;
  cin >> N;
  vector<ll> A(N);
  for (size_t i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  ll max_odd = numeric_limits<ll>::min();
  for(int i = 0;i < N;i++){
      ll max_even = numeric_limits<ll>::min();
      ll odd_at_max_even;
      ll odd = 0;
      ll even = 0;
      for (size_t j = 0; j <= i; j++)
      {
          if (j % 2 == 0){
              odd += A[j];
          }else{
              even += A[j];
          }
      }
      for (size_t j = 0; j <= i; j++)
      {
          if (j != i && even > max_even){
              max_even = even;
              odd_at_max_even = odd;
          }
          odd -= A[j];
          swap(odd,even);
      }
      odd = 0;
      even = 0;
      for (size_t j = i; j <N; j++)
      {
          if ((j-i) % 2 == 0){
              odd += A[j];
          }else{
              even += A[j];
          }
          if (j != i && even > max_even){
              max_even = even;
              odd_at_max_even = odd;
          }
      }
    //   cout << max_even << endl;
    //   cout << odd_at_max_even << endl;
      max_odd = max(max_odd,odd_at_max_even);
  }
  cout << max_odd << endl;
  return 0;
}
