#define _USE_MATH_DEFINES
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
#include <unordered_map>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
  ll N, M;
  cin >> N >> M;
  vector<ll> A(M);
  for (int i = 0; i < M; i++)
  {
    cin >> A[i];
    A[i]--;
  }
  vector<ll> after_change(N);
  // 値がある場所
  vector<ll> rev_after_change(N);
  vector<ll> before_change(N);
  vector<ll> rev_before_change(N);
  iota(after_change.begin(), after_change.end(), 0);
  iota(rev_after_change.begin(), rev_after_change.end(), 0);
  iota(before_change.begin(), before_change.end(), 0);
  iota(rev_before_change.begin(), rev_before_change.end(), 0);
  for (int i = 1; i < M; i++)
  {
    swap(after_change[A[i]], after_change[A[i] + 1]);
    rev_after_change[after_change[A[i]]] = A[i];
    rev_after_change[after_change[A[i] + 1]] = A[i] + 1;
  }

  for (int i = 0; i < M; i++)
  {
    // for(int j = 0;j < N;j++){
    //   cout << before_change[j] << ",";
    // }
    // cout <<endl;
    // for(int j = 0;j < N;j++){
    //   cout << after_change[j] << ",";
    // }
    // cout << endl;
    // for(int j = 0;j < N;j++){
    //   cout << rev_after_change[j] << ",";
    // }
    // cout << endl;
    cout << rev_after_change[rev_before_change[0]] + 1 << "\n";
    ll change_index1 = rev_after_change[A[i+1]];
    ll change_index2 = rev_after_change[A[i+1]+1];
    swap(after_change[change_index1], after_change[change_index2]);
    rev_after_change[after_change[change_index1]] = change_index1;
    rev_after_change[after_change[change_index2]] = change_index2;

    swap(before_change[A[i]], before_change[A[i] + 1]);
    rev_before_change[before_change[A[i]]] = A[i];
    rev_before_change[before_change[A[i] + 1]] = A[i] + 1;

  }
  cout << flush;
  return 0;
}