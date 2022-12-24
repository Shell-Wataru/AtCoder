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
  vector<pair<string,string>> A(N);
  map<string,ll> name_count;
  for(int i = 0;i < N;i++){
    cin >> A[i].first >> A[i].second;
    name_count[A[i].first]++;
    name_count[A[i].second]++;
  }
  for(int i = 0;i < N;i++){
    if (A[i].first == A[i].second){
      if (name_count[A[i].first] > 2){
        cout << "No" << endl;
        return 0;
      }
    }else{
      if (name_count[A[i].first] > 1 && name_count[A[i].second] > 1){
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}