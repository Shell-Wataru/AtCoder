#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <ctime>
#include <map>
#include <boost/multiprecision/cpp_int.hpp>
#include <string>
#include <numeric>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

const long long BASE_NUM = 1000000007;

int main()
{
  ll N;
  cin >> N;
  vector<vector<ll>> C(N,vector<ll>(N,0));
  ll total = 0;
  for (ll i = 0; i < N; i++)
  {
    for (ll j = 0; j < N; j++)
    {
      cin >> C[i][j];
      total += C[i][j];
    }
  }
  vector<ll> A(N,0);
  vector<ll> B(N,0);
  for (size_t i = 0; i < N; i++)
  {
    B[i] = C[0][i];
  }

  ll min_a = 0;;
  for (size_t i = 0; i < N; i++)
  {
    A[i] = C[i][0] - B[0];
    min_a = min(min_a,A[i]);
  }
  bool is_ok = true;
  for(int i = 0; i < N;i++){
    A[i] += - min_a;
    B[i] += min_a;
    if (B[i] < 0){
      is_ok = false;
    }
  }
  for (ll i = 0; i < N; i++)
  {
    for (ll j = 0; j < N; j++)
    {
      if (C[i][j] != A[i] + B[j]){
        is_ok = false;
      }
    }
  }
  // for(int i = 0;i < N;i++){
  //     if (i != 0){
  //       cout << " ";
  //     }
  //     cout << A[i];
  //   }
  //   cout << endl;
  //   for(int i = 0;i < N;i++){
  //     if (i != 0){
  //       cout << " ";
  //     }
  //     cout << B[i];
  //   }
  //   cout << endl;
  if (is_ok){
    cout << "Yes" << endl;
    for(int i = 0;i < N;i++){
      if (i != 0){
        cout << " ";
      }
      cout << A[i];
    }
    cout << endl;
    for(int i = 0;i < N;i++){
      if (i != 0){
        cout << " ";
      }
      cout << B[i];
    }
    cout << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}