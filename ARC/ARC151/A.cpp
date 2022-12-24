#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <numeric>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int solve()
{
  ll N;
  cin >> N;
  string S,T;
  cin >> S >> T;
  string U(N,'*');
  ll not_same_count = 0;
  deque<ll> same;
  for(int i = 0;i < N;i++){
    if (S[i] !=  T[i]){
      not_same_count++;
    }else{
      same.push_back(i);
    }
  }
  if ( not_same_count % 2 == 1){
    cout << -1 << endl;
    return 0;
  }
  ll s_count = 0;
  ll t_count = 0;
  for(int i = 0;i < N;i++){
    // cout << "!" << endl;
    if (S[i] == T[i]){
      U[i] = '0';
    }else if (S[i] == '0' && T[i] == '1'){
      if (s_count+1 - t_count <= not_same_count - 1){
        U[i] = '0';
        s_count++;
        not_same_count--;
      }else{
        U[i] = '1';
        t_count++;
        not_same_count--;
      }
    }else{
      if (t_count + 1 - s_count <= not_same_count - 1){
        U[i] = '0';
        t_count++;
        not_same_count--;
      }else{
        U[i] = '1';
        s_count++;
        not_same_count--;
      }
    }
  }
  cout << U << endl;
  return 0;
}
int main()
{
  // ll T;
  // cin >> T;
  // for(int i = 0;i < T;i++){
    solve();
  // }
  cout << flush;
  return 0;
}