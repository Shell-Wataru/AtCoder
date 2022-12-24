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
  vector<ll> B(N);
  set<ll> bset;
  for(int i = 0;i < N;i++){
    cin >> A[i];
  }
  for(int i = 0;i < N;i++){
    cin >> B[i];
    bset.insert(B[i]);
  }
  ll completely_matched = 0;
  ll matched = 0;
  for(int i = 0;i < N;i++){
    if (A[i] == B[i]){
      completely_matched++;
    }
    if (bset.find(A[i]) != bset.end()){
      matched++;
    }
  }
  cout << completely_matched << "\n" << matched - completely_matched << endl;
  return 0;
}