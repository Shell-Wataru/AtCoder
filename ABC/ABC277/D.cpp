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
#include <unordered_set>
#include <unordered_map>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
  ll N,M;
  cin >> N >> M;
  vector<ll> A(N);
  ll total = 0;
  unordered_set<ll> used;
  for(int i = 0;i < N;i++){
    cin >> A[i];
    total += A[i];
    used.insert(A[i]);
  }
  sort(A.begin(),A.end());
  if (used.size() == M){
    cout << 0 << endl;
    return 0;
  }
  vector<vector<ll>> ranges;
  ll max_removed = 0;
  for(int i = 0;i < N;i++){
    if (ranges.empty() || ranges.back()[1] + 1 < A[i]){
      if (!ranges.empty()){
        max_removed = max(max_removed,ranges.back()[2]);
      }
      ranges.push_back({A[i],A[i],A[i]});
    }else if (ranges.back()[1] + 1 == A[i]){
      ranges.back()[1] = A[i];
      ranges.back()[2]+= A[i];
    }else if (ranges.back()[1] == A[i]){
      ranges.back()[2]+= A[i];
    }
  }
  if (ranges.back()[1] == M-1 && ranges.front()[0] == 0){
    max_removed = max(max_removed,ranges.back()[2]+ ranges.front()[2]);
  }else{
    max_removed = max(max_removed,ranges.back()[2]);
  }
  // for(auto a:A){
  //   cout << a  << ",";
  // }
  // cout << endl;
  // for(auto a:ranges){
  //   cout << a[0]  << "," << a[1] << "," << a[2] << endl;
  // }
  // cout << endl;
  // cout << total << endl;
  // cout << max_removed << endl;
  cout << total - max_removed << endl;
  return 0;
}