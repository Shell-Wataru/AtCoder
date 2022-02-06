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

int main()
{
  ll N;
  cin >> N;
  vector<ll> A(N);
  for(int i = 0;i < N;i++){
    cin >> A[i];
    // cout << bitset<8>(A[i]) << endl;
  }
  ll all_xor = 0;
  for(int i = 0;i < N;i++){
    all_xor ^=  A[i];
  }
  bool found = false;
  for(int i = 0;i < N;i++){
    if (all_xor == A[i]){
      found = true;
      break;
    }
  }
  if (found || N % 2 == 1){
    cout << "Win" << endl;
  }else{
    cout << "Lose" << endl;
  }

  return 0;
}
