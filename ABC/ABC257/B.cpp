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
  ll N, K , Q;
  cin >> N >> K >> Q;
  vector<ll> A(K);
  for (int i = 0; i < K; i++)
  {
    cin >> A[i];
  }
  for(int i = 0;i < Q;i++){
    ll l;
    cin >> l;
    l--;
    if (A[l] == N){
      continue;
    }else if (A[l] + 1 == A[l+1]){
      continue;
    }else{
      A[l]++;
    }
  }
  for(int i =0 ;i < K;i++){
    if (i!= 0){
      cout << " ";
    }
    cout << A[i];
  }
  cout <<endl;
  return 0;
}