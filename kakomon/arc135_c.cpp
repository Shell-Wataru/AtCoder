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
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;

vector<ll> count_bits(ll N, vector<ll> &A)
{
  vector<ll> counts(30, 0);
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < 30; j++)
    {
      if (A[i] & 1ll << j)
      {
        counts[j]++;
      }
    }
  }
  return counts;
}

int main()
{
  ll N;
  cin >> N;
  vector<ll> A(N);
  ll maximum = 0;
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
    maximum += A[i];
  }
  vector<ll> counts = count_bits(N, A);
  for(int i = 0;i < N;i++){
      ll value = 0;
      for(int j = 0;j < 30;j++){
          if (A[i] & 1ll<<j){
              value += (N-counts[j])*(1ll<<j);
          }else{
              value += (counts[j])*(1ll<<j);
          }
      }
      maximum = max(maximum,value);
  }
  cout << maximum << endl;
  return 0;
}
