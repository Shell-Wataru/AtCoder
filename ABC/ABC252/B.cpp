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
  ll N,K;
  cin >> N >> K;
  set<ll> A;
  ll maximum = 0;
  for(int i = 0;i < N;i++){
    ll a;
    cin >> a;
    if (a > maximum){
      maximum = a;
      A.clear();
      A.insert(i);
    }else if (a == maximum){
      A.insert(i);
    }
  }
  bool found = false;
  for(int i = 0;i < K;i++){
    ll b;
    cin >> b;
    b--;
    if (A.find(b) != A.end()){
      found = true;
    }
  }
  if (found){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}