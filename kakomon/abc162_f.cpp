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
#include <set>
using namespace std;
using ll = long long;

int main()
{
  ll N;
  cin >> N;
  vector<ll> A(N);
  for(int i = 0;i < N;i++){
    cin >> A[i];
  }
  vector<vector<ll>> DParu(N+1,vector<ll>(3,numeric_limits<ll>::min()/2));
  vector<vector<ll>> DPnai(N+1,vector<ll>(3,numeric_limits<ll>::min()/2));
  DPnai[0][0] = 0;
  for(int i = 0;i < N;i++){
    for(int j = 0;j < 3;j++){
      DPnai[i+1][j] = max(DPnai[i+1][j],DParu[i][j]);
    }
    for(int j = 0;j < 2;j++){
      DPnai[i+1][j+1] = max(DPnai[i+1][j+1],DPnai[i][j]);
    }
    for(int j = 0;j < 3;j++){
      DParu[i+1][j] = max(DParu[i+1][j],DPnai[i][j] + A[i]);
    }
  }
  if (N % 2 == 1){
    cout << max(DParu[N][2],DPnai[N][1]) << endl;
  }else{
    cout << max(DParu[N][1],DPnai[N][0]) << endl;
  }
  return 0;
}
