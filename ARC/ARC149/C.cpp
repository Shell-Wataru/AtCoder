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

using namespace std;
using ll = long long;

int main()
{
  ll N,M;
  cin >> N >> M;
  vector<ll> X(N);
  vector<ll> D(M);
  for(int i = 0;i < N;i++){
    cin >> X[i];
  }
  for(int i = 0;i < M;i++){
    cin >> D[i];
  }
  ll current_x = 0;
  unordered_map<ll,ll> answers;
  for(int i = 0;i < 1000;i++){
    vector<pair<ll,ll>> positives;
    vector<pair<ll,ll>> negatives;
    while(current_x < N && X[current_x] < 1000*(i+1)+1){
      positives.push_back({X[current_x],X[current_x]});
      current_x++;
    }
    ll base = 0;
    for(int j = 0;j < M;j++){
      base += D[i];
      if (!positives.empty() && base >= positives[0].first){

      }
    }
  }
  return 0;
}
